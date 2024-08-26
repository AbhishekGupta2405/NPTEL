#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int dist[N][N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }
        
        int n, m, ct;
        cin >> n >> m >> ct;
        
        for (int i = 0; i < m; i++) {
            int x, y, wt;
            cin >> x >> y >> wt;
            dist[x][y] = wt;
            dist[y][x] = wt;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<pair<int, int>> tt(n, {0, 0});
        vector<int> con(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= ct) {
                    tt[i].first += dist[i][j];
                    con[i]++;
                }
            }
        }

        int index = 0;
        int max_con = con[0];
        int min_t = tt[0].first;

        for (int i = 1; i < n; i++) {
            if (con[i] > max_con) {
                max_con = con[i];
                min_t = tt[i].first;
                index = i;
            } else if (con[i] == max_con) {
                if (tt[i].first < min_t) {
                    min_t = tt[i].first;
                    index = i;
                } else if (tt[i].first == min_t && i > index) {
                    index = i;
                }
            }
        }

        cout << index << endl;
    }
}
