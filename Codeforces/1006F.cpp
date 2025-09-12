// https://codeforces.com/problemset/problem/1006/F
// Xor-Paths

#define ll long long
#include <bits/stdc++.h>
using namespace std;

void dfs1(int i, int j, ll current_xor, int steps, vector<vector<unordered_map<ll, ll>>> &dp, const vector<vector<ll>> &grid, int n, int m)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return;

  current_xor ^= grid[i][j];
  if (!steps)
  {
    dp[i][j][current_xor]++;
    return;
  }

  dfs1(i + 1, j, current_xor, steps - 1, dp, grid, n, m);
  dfs1(i, j + 1, current_xor, steps - 1, dp, grid, n, m);
}

void dfs2(int i, int j, ll current_xor, int steps, ll &ans, const ll target_xor, const vector<vector<unordered_map<ll, ll>>> &dp, const vector<vector<ll>> &grid, int n, int m)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return;

  if (!steps)
  {
    auto it = dp[i][j].find(current_xor ^ target_xor);
    if (it != dp[i][j].end())
    {
      ans += it->second;
    }
    return;
  }

  current_xor ^= grid[i][j];

  dfs2(i - 1, j, current_xor, steps - 1, ans, target_xor, dp, grid, n, m);
  dfs2(i, j - 1, current_xor, steps - 1, ans, target_xor, dp, grid, n, m);
}

int main()
{
  int n, m;
  ll target_xor;
  cin >> n >> m >> target_xor;
  vector<vector<ll>> grid(n, vector<ll>(m));
  vector<vector<unordered_map<ll, ll>>> dp(n, vector<unordered_map<ll, ll>>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  int total_steps = n + m - 2;
  int steps1 = total_steps / 2;
  int steps2 = total_steps - steps1;

  ll ans = 0;

  dfs1(0, 0, 0, steps1, dp, grid, n, m);
  dfs2(n - 1, m - 1, 0, steps2, ans, target_xor, dp, grid, n, m);

  cout << ans << endl;

  return 0;
}