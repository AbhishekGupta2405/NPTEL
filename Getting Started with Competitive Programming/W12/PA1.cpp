#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int MOD = 1e9 + 7;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string r, s;
        cin>>r>>s;
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        for(int j = 0; j<=m; j++){
            dp[0][j] = 1;
             }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(r[i-1] == s[j-1]){
                        dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
                    } else{
                        dp[i][j] = (dp[i][j-1]) % MOD;
                    }
                }
            }
       cout<<dp[n][m] % MOD <<endl;
    }
}