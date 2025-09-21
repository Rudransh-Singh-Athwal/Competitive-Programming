// https://codeforces.com/problemset/problem/894/A
// QAQ

#include <bits/stdc++.h>
using namespace std;

int fn(int index, int pos, string &inputString, string targetString, vector<vector<int>> &dp)
{
  if (pos == targetString.length())
    return 1;

  if (index >= inputString.length())
    return 0;

  if (dp[index][pos] != -1)
    return dp[index][pos];

  int notPick = fn(index + 1, pos, inputString, targetString, dp);
  int pick = 0;
  if (inputString[index] == targetString[pos])
  {
    pick = fn(index + 1, pos + 1, inputString, targetString, dp);
  }

  return dp[index][pos] = pick + notPick;
}

int main()
{
  string inputString;
  cin >> inputString;
  int n = inputString.length();

  string targetString = "QAQ";
  int m = targetString.length();

  vector<vector<int>> dp(n, vector<int>(m, -1));

  int ans = fn(0, 0, inputString, targetString, dp);

  cout << ans << endl;

  return 0;
}