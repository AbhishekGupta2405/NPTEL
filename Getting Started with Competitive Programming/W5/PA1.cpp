#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
vector<int> g[N];

int vis[N];
int level[N];
int parent[N];

int bfs(int source, int dest){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    parent[source] = -1;

    while(!q.empty()){
        int cur_v = q.front();
        if(cur_v == dest) break;
        q.pop();
        for(int child : g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
                parent[child] = cur_v;
            }
        }
    }
    if(vis[dest]==0) return -1;
    return level[dest];
}

void reset(){
    for(int i=0; i<N; i++){
        g[i].clear();
        vis[i] = 0;
        level[i] = 0;
        parent[i] = -1;
    }
}

void path(int source, int dest){
    vector<int> p;
    for(int v = dest; v != -1; v= parent[v]){
        p.push_back(v);
    }
    reverse(p.begin(), p.end());

    for(size_t i = 0; i < p.size(); i++) {
        cout << p[i];
        if (i != p.size() - 1) {
            cout << " ";
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        int n, a;
        cin>>n>>a;
        for(int i=0; i<a; i++){
            int v1, v2;
            cin>>v1>>v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        for(int i=0; i<=n; i++){
            sort(g[i].begin(), g[i].end());
        }

        int distance = bfs(1, n);

        if(distance != -1){
            path(1, n);
        } else{
            cout << "-1\n";
        }    
    }
}