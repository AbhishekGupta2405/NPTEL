#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  ll testCases;
  cin >> testCases;
  while (testCases--)
  {
    ll remainingHours, numBoxes;
    cin >> remainingHours >> numBoxes;

    ll clothesPerBox[numBoxes];
    for (ll i = 0; i < numBoxes; i++)
    {
      cin >> clothesPerBox[i];
    }

    ll totalClothes = 0;
    for (ll i = 0; i < numBoxes; i++)
    {
      totalClothes += clothesPerBox[i];
    }

    ll minRate = 1;
    ll maxRate = totalClothes;
    ll sortingRate = maxRate;
    while (minRate <= maxRate)
    {
      ll midRate = (minRate + maxRate) / 2;
      ll timeTaken = 0;

      for (ll i = 0; i < numBoxes; i++)
      {
        timeTaken += (clothesPerBox[i] + midRate - 1) / midRate;
      }

      if (timeTaken <= remainingHours)
      {
        sortingRate = midRate;
        maxRate = midRate - 1;
      }
      else
      {
        minRate = midRate + 1;
      }
    }
    cout << sortingRate << endl;
  }
  return 0;
}