#include<bits/stdc++.h>
using namespace std;
# define ll long long
const int N = 1e6 + 10;
const int M = 1e9 + 7;
ll dp[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        ll n;
        cin >> n;

        dp[1] = 1;
        ll a = 1, b = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + a + b) % M;
            ll c = a;
            a = b;
            b = (c + b) % M;
        }

        cout << dp[n] << endl;
    }
}