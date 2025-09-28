// https://codeforces.com/problemset/problem/1469/B
// Red and Blue

#include <bits/stdc++.h>
using namespace std;

int fn(int i, int j, int maxSum, const vector<int> &red, const int n, const vector<int> &blue, const int m, vector<vector<int>> &dp)
{
  if (i == n && j == m)
  {
    return maxSum;
  }

  if (dp[i][j] != -1)
    return dp[i][j];

  int pickRed = 0;
  int pickBlue = 0;

  if (i < n)
  {
    pickRed = fn(i + 1, j, maxSum + red[i], red, n, blue, m, dp);
  }

  if (j < m)
  {
    pickBlue = fn(i, j + 1, maxSum + blue[j], red, n, blue, m, dp);
  }

  return dp[i][j] = max(maxSum, max(pickRed, pickBlue));
}

int main()
{
  int n;
  cin >> n;
  vector<vector<vector<int>>> input(n);

  for (int i = 0; i < n; i++)
  {
    vector<int> red;
    vector<int> blue;

    int blueEls;
    cin >> blueEls;
    for (int j = 0; j < blueEls; j++)
    {
      int el;
      cin >> el;
      blue.push_back(el);
    }

    int redEls;
    cin >> redEls;
    for (int j = 0; j < redEls; j++)
    {
      int el;
      cin >> el;
      red.push_back(el);
    }

    input[i].push_back(red);
    input[i].push_back(blue);
  }

  for (auto it : input)
  {
    int n = it[0].size();
    int m = it[1].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = fn(0, 0, 0, it[0], n, it[1], m, dp);
    cout << ans << endl;
  }

  return 0;
}