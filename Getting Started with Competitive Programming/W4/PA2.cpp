#include <bits/stdc++.h>

using namespace std;

void dfs(int island, vector<int> adj[], bool visited[]) {
    visited[island] = true;

    for (int neighbor : adj[island]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int islands, boat_tours;
        cin >> islands >> boat_tours;

        vector<int> adj[islands + 1];
        bool visited[islands + 1];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < boat_tours; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int archipelagos = 0;

        for (int i = 1; i <= islands; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                archipelagos++;
            }
        }

        cout << archipelagos << endl;
    }
}
