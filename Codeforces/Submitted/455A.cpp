// https://codeforces.com/problemset/problem/455/A
// Boredom

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll fn(int index, const vector<pair<int, int>> &nums, unordered_map<int, ll> &dp)
{
  if (index >= (int)nums.size() || index < 0)
    return 0;

  if (dp.count(index))
    return dp[index];

  ll notPick = fn(index + 1, nums, dp);
  ll pick = 1LL * nums[index].first * nums[index].second;
  if (nums[index + 1].first == nums[index].first + 1)
    pick += fn(index + 2, nums, dp);
  else
    pick += fn(index + 1, nums, dp);

  return dp[index] = max(pick, notPick);
}

int main()
{
  int t;
  cin >> t;

  unordered_map<int, int> mp;
  for (int i = 0; i < t; i++)
  {
    int x;
    cin >> x;
    if (mp.count(x))
      mp[x]++;
    else
      mp[x] = 1;
  }

  vector<pair<int, int>> nums;
  unordered_map<int, ll> dp;
  for (auto it : mp)
  {
    nums.push_back({it.first, it.second});
  }

  sort(nums.begin(), nums.end());
  ll ans = fn(0, nums, dp);
  cout << ans << endl;

  return 0;
}