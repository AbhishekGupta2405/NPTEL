#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<vector<ll>> dp(n+1, vector<ll>(m + 1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i == 1 || j == 1){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
}