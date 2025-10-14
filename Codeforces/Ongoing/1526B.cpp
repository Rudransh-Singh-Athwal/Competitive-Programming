// https://codeforces.com/problemset/problem/1526/B
// I Hate 1111
// Codeforces 1526B -> I Hate 1111

#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool fn(ll num, ll div, int len, unordered_map<unsigned ll, bool> &dp)
{
  if (num == 0)
    return true;
  if (num < 0 || len > 9)
    return false;

  // Pack two 32-bit values (num and div) into a single 64-bit integer so it can be used as a unique key
  unsigned ll key = ((unsigned ll)num << 32) | (unsigned ll)div;
  if (dp.count(key))
    return dp[key];

  bool notPick = fn(num, div * 10 + 1, len + 1, dp);
  bool pick = fn(num - div, div, len, dp);

  return dp[key] = pick || notPick;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  unordered_map<unsigned ll, bool> dp;

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  for (auto el : nums)
  {
    if (fn(el, 11LL, 2, dp) == true)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}