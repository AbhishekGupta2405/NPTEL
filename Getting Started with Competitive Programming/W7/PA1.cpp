#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e9 + 10;
vector<pair<ll, ll>> g[110];

ll prim(ll source, ll n)
{
    vector<ll> vis(n + 1, 0);
    vector<ll> dist(n + 1, INF);
    
    set<pair<ll, ll>> st;
    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        ll v = node.second;
        st.erase(st.begin());

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto child : g[v])
        {
            ll child_v = child.first;
            ll weight = child.second;

            if (!vis[child_v] && weight < dist[child_v])
            {
                st.erase({dist[child_v], child_v});
                dist[child_v] = weight;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    ll mst_weight = 0;
    for (ll i = 1; i <= n; i++)
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        
        for (ll i = 1; i <= n; i++) 
        {
            g[i].clear();
        }
        
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                ll wt;
                cin >> wt;
                if (i != j)
                {
                    g[i].push_back({j, wt});
                }
            }
        }

        cout << x * prim(1, n) << endl;
    }
    return 0;
}
