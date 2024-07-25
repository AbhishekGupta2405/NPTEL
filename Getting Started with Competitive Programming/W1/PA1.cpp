#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, M;
    cin >> n >> M;
    string s;
    cin >> s;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      int num = s[i] - '0';
      m[num]++;
    }

    int city = -1;
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
      if ((*it).second >= 2 && (*it).first >= city)
      {
        city = (*it).first;
      }
    }

    cout << city << endl;
  }
}