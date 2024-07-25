#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isAscending(ll arr[], ll size)
{
  for (ll i = 0; i < size - 1; ++i)
  {
    if (arr[i] > arr[i + 1])
    {
      return false;
    }
  }
  return true;
}

bool isDescending(ll arr[], ll size)
{
  for (ll i = 0; i < size - 1; ++i)
  {
    if (arr[i] < arr[i + 1])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll h[n];
    for (ll i = 0; i < n; i++)
    {
      cin >> h[i];
    }

    if (isAscending(h, n))
    {
      cout << "L" << endl;
    }
    else if (isDescending(h, n))
    {
      cout << "R" << endl;
    }
    else
    {
      cout << "N" << endl;
    }
  }
}
