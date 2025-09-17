// https://codeforces.com/problemset/problem/1420/C1
// Pokémon Army (easy version)
// Codeforces 1420C1 -> Pokémon Army (easy version)

#include <bits/stdc++.h>
using namespace std;

int fn(int index, bool flag, vector<int> &strength, vector<vector<bool>> &dp)
{
  if (index == strength.size())
  {
    return 0;
  }

  int notPick = fn(index + 1, flag, strength, dp);
  int pick = 0;
  if (flag)
  {
    pick = fn(index + 1, !flag, strength, dp) + strength[index];
  }
  else
  {
    pick = fn(index + 1, !flag, strength, dp) - strength[index];
  }

  return max(pick, notPick);
}

int main()
{
  vector<vector<int>> input;
  int n;
  cin >> n;

  vector<vector<bool>> dp(n, vector<bool>(2, -1));

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

  for (auto it : input)
  {
    int ans = fn(0, true, it, dp);
    cout << ans << endl;
  }

  return 0;
}