// https://codeforces.com/problemset/problem/1420/C1
// Pokémon Army (easy version)
// Codeforces 1420C1 -> Pokémon Army (easy version)

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll fn(int index, bool flag, vector<int> &strength, vector<vector<ll>> &dp)
{
  if (index == strength.size())
  {
    return 0;
  }

  if (dp[index][flag] != -1)
    return dp[index][flag];

  ll notPick = fn(index + 1, flag, strength, dp);
  ll pick = 0;
  if (flag)
  {
    pick = fn(index + 1, !flag, strength, dp) + strength[index];
  }
  else
  {
    pick = fn(index + 1, !flag, strength, dp) - strength[index];
  }

  return dp[index][flag] = max(pick, notPick);
}

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
    vector<vector<ll>> dp(strength.size(), vector<ll>(2, -1));
    ll ans = fn(0, true, strength, dp);
    cout << ans << endl;
  }

  return 0;
}