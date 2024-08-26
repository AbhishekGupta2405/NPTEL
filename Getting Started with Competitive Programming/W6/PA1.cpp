#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

int dijkstra(int source, int n)
{
    vector<int> vis(n + 1, 0);
    vector<int> dist(n + 1, INF);

    set<pair<int, int>> st;
    st.insert({0,
               source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v],
                           child_v});
            }
        }
    }
    return dist[n] == INF ? -1 : dist[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,
                        wt});
        g[y].push_back({x,
                        wt});
    }
    cout << dijkstra(1, n) << endl;
}