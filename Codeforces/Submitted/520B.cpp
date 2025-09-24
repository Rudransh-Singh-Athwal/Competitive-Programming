// https://codeforces.com/problemset/problem/520/B
// Two Buttons

#include <bits/stdc++.h>
using namespace std;

int fn(int n, int target)
{
  if (n == target)
    return 0;

  // if only option is to decrement (pressing the blue button till target)
  if (n > target)
    return n - target;

  int ops = 0;
  while (target > n)
  {
    if (target % 2 == 0)
      target /= 2;
    else
      target++;
    ops++;
  }

  return ops + (n - target);
}

int main()
{
  int n, target;
  cin >> n >> target;
  unordered_map<int, int> dp;
  dp[0] = INT_MAX;

  if (n == target)
  {
    cout << 0 << endl;
    return 0;
  }
  int ans = fn(n, target);
  cout << ans << endl;

  return 0;
}