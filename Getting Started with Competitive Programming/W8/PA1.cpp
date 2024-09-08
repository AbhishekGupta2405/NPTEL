#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 505;
const ll INF = 1e18;

struct Edge {
    int to, rev; 
    ll cap, flow; 
};

vector<Edge> edges;
vector<vi> adj;
vi level, ptr;

void addEdge(int u, int v, ll cap) {
    edges.push_back({v, (int)edges.size() + 1, cap, 0});
    edges.push_back({u, (int)edges.size() - 1, 0, 0});
    adj[u].push_back((int)edges.size() - 2);
    adj[v].push_back((int)edges.size() - 1);
}

bool bfs(int s, int t) {
    level.assign(MAXN, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i : adj[u]) {
            Edge &e = edges[i];
            if (e.cap - e.flow > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] != -1;
}

ll dfs(int u, int t, ll flow) {
    if (u == t) return flow;

    for (int &i = ptr[u]; i < (int)adj[u].size(); ++i) {
        Edge &e = edges[adj[u][i]];

        if (e.cap - e.flow > 0 && level[e.to] == level[u] + 1) {
            ll pushed = dfs(e.to, t, min(flow, e.cap - e.flow));
            if (pushed > 0) {
                e.flow += pushed;
                edges[e.rev].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t) {
    ll max_flow = 0;

    while (bfs(s, t)) {
        ptr.assign(MAXN, 0);
        while (ll pushed = dfs(s, t, INF)) {
            max_flow += pushed;
        }
    }

    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int p, w;
        cin >> p >> w;

        edges.clear();
        adj.assign(p + 1, vi()); 
        level.assign(p + 1, -1); 

        for (int i = 0; i < w; ++i) {
            int pi, pj;
            cin >> pi >> pj;
            addEdge(pi, pj, 1); 
        }

        ll max_days = dinic(1, p);

        cout << max_days << endl; 
    }

    return 0;
}