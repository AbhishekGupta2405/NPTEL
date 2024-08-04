#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);

    for (ll i = 0; i < n; ++i)
    {
      cin >> arr[i];
    }

    ll maxSoFar = arr[0], maxEndingHere = arr[0];
    ll start = 0, end = 0, tempStart = 0;

    for (ll i = 1; i < n; ++i)
    {
      maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
      if (maxEndingHere > maxSoFar)
      {
        maxSoFar = maxEndingHere;
        start = tempStart;
        end = i;
      }
      if (maxEndingHere < 0)
      {
        maxEndingHere = 0;
        tempStart = i + 1;
      }
    }

    ll totalSum = 0;
    for (ll i = 0; i < n; ++i)
    {
      totalSum += arr[i];
    }

    ll maxProfit = max(maxSoFar, totalSum);

    cout << maxProfit * x << endl;
  }
  return 0;
}