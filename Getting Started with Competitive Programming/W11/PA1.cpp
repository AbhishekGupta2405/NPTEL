#include <bits/stdc++.h>
using namespace std;

int palindrome(const string& a, int left, int right) {
    int n = a.length();
    while (left >= 0 && right < n && a[left] == a[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;
        string a;
        cin >> a;
        
        int maxlen = 0;
        
        for (int i = 0; i < n; i++) {
            
            int len1 = palindrome(a, i, i);
            
            int len2 = palindrome(a, i, i + 1);
            
            maxlen = max(maxlen, max(len1, len2));
        }
        
        if (maxlen * s >= x) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
}
