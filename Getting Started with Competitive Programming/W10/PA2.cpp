#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int v[N];

int power(int start, int end) {
    dp[start] = v[start];
    dp[start + 1] = max(v[start], v[start + 1]);
    int p = 0;
    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    }
    return dp[end];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << v[1] << endl;
            continue;
        }

        int max1 = power(1, n - 1);

        int max2 = power(2, n);

        cout << max(max1, max2) << endl;
    }
}