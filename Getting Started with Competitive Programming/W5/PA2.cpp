#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
vector<vector<int> > v;
vector<vector<int> > vis;

void dfs(int x, int y, int n, int m){
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(vis[x][y] || v[x][y] == 0) return;

    vis[x] [y] = 1;

    dfs(x-1, y, n, m);
    dfs(x+1, y, n, m);
    dfs(x, y-1, n, m);
    dfs(x, y+1, n, m);
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        v.resize(n, vector<int>(m));
        vis.resize(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>v[i] [j];
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, n, m);
                    count++;
                }
            }
        }
        cout<<count<<endl;
        v.clear();
        vis.clear();
    }
}