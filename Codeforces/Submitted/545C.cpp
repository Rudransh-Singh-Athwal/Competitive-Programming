// https://codeforces.com/problemset/problem/545/C
// Woodcutters

#define ll long long
#define ull unsigned long long
#include <bits/stdc++.h>
using namespace std;

int fn(int index, ll lastPos, vector<pair<ll, ll>> &nums, int n, unordered_map<ull, ll> &dp)
{
  if (index >= n)
    return 0;

  ull key = ((ull)index << 32) || (ull)lastPos;

  if (dp.find(key) != dp.end())
    return dp[key];

  ll x = nums[index].first;
  ll h = nums[index].second;

  if (x <= lastPos)
    return fn(index + 1, lastPos, nums, n, dp);

  int best = 0;

  // cut to the left
  if (x - h > lastPos)
    best = max(best, 1 + fn(index + 1, x, nums, n, dp));

  // cut to the right
  if (index == n - 1 || x + h < nums[index + 1].first)
    best = max(best, 1 + fn(index + 1, x + h, nums, n, dp));

  // don't cut
  best = max(best, fn(index + 1, x, nums, n, dp));

  return dp[key] = best;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<ll, ll>> nums;
  unordered_map<ull, ll> dp;

  for (int i = 0; i < n; i++)
  {
    ll coordinate, height;
    cin >> coordinate >> height;
    nums.push_back({coordinate, height});
  }

  sort(nums.begin(), nums.end());

  int ans = fn(0, LLONG_MIN / 4, nums, n, dp);
  cout << ans << endl;

  return 0;
}