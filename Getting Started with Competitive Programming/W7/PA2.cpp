#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

int prim(int source, int n)
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    vector<int> visitOrder;

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        st.erase(st.begin());

        if (vis[v]) continue;
        vis[v] = 1;
        visitOrder.push_back(v);

        for (auto child : g[v])
        {
            int child_v = child.first;
            int weight = child.second;

            if (!vis[child_v] && weight < dist[child_v])
            {
                dist[child_v] = weight;
                st.insert({dist[child_v], child_v});
            }
        }
    }


    int mst_weight = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            mst_weight += dist[i];
        }
    }
    return mst_weight;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m;
    cin >> n >> m;
    for(int i=0; i<N; i++){
        g[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    cout << prim(1, n)<<endl;
    }
}
