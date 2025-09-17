// https://codeforces.com/problemset/problem/1420/C1
// Pokémon Army (easy version)
// Codeforces 1420C1 -> Pokémon Army (easy version)

#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<vector<int>> input;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int m, swaps;
    cin >> m >> swaps;
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    input.push_back(temp);
  }

  for (auto strength : input)
  {
    vector<ll> next(2, 0);
    vector<ll> curr(2, 0);

    for (int index = strength.size() - 1; index >= 0; index--)
    {
      for (int flag = 0; flag <= 1; flag++)
      {
        ll notPick = next[flag];
        ll pick = 0;
        if (flag)
        {
          pick = next[!flag] + strength[index];
        }
        else
        {
          pick = next[!flag] - strength[index];
        }

        curr[flag] = max(pick, notPick);
      }
      next = curr;
    }

    ll ans = next[true];
    cout << ans << endl;
  }

  return 0;
}