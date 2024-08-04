#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll x, h;
    cin >> x >> h;
    ll c[x];

    for (ll i = 0; i < x; i++)
    {
      cin >> c[i];
    }

    sort(c, c + x);

    ll min1 = c[0];
    ll min2 = c[1];

    if ((min1 + min2) <= h)
    {
      cout << h - (min1 + min2) << endl;
    }
    else
    {
      cout << h << endl;
    }
  }
  return 0;
}