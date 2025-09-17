// https://codeforces.com/problemset/problem/189/A
// Cut Ribbon

#include <bits/stdc++.h>
using namespace std;

int fn(int len, const int &a, const int &b, const int &c, unordered_map<int, int> &dp)
{
  if (len == 0)
    return 0;
  if (a > len && b > len && c > len)
    return INT_MIN;

  if (dp.count(len))
    return dp[len];

  int cutA = INT_MIN, cutB = INT_MIN, cutC = INT_MIN;

  if (a <= len)
  {
    cutA = 1 + fn(len - a, a, b, c, dp);
  }
  if (b <= len)
  {
    cutB = 1 + fn(len - b, a, b, c, dp);
  }
  if (c <= len)
  {
    cutC = 1 + fn(len - c, a, b, c, dp);
  }

  return dp[len] = max(cutA, max(cutB, cutC));
}

int main()
{
  int len, a, b, c;
  cin >> len >> a >> b >> c;
  unordered_map<int, int> dp;

  int piecesofRibbon = fn(len, a, b, c, dp);

  piecesofRibbon = max(piecesofRibbon, 0);

  cout << piecesofRibbon << endl;

  return 0;
}