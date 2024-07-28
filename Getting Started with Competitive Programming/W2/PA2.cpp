#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vi asorted = a;
    sort(asorted.begin(), asorted.end());

    ll maxWorkers = 0;
    ll currentMax = -1;

    for (ll i = 0; i < n; i++)
    {
      currentMax = max(currentMax, a[i]);
      if (currentMax == asorted[i])
      {
        maxWorkers++;
        currentMax = -1;
      }
    }

    cout << maxWorkers << endl;
  }
  return 0;
}
