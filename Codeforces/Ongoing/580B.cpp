// https://codeforces.com/problemset/problem/580/B
// Kefa and Company
// Codeforces 580B -> Kefa and Company

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll fn(int index, int prev, const int d, vector<vector<int>> &nums, vector<vector<ll>> &dp)
{
  if (index >= nums.size() || (prev != -1 && nums[index][0] - nums[prev][0] >= d))
    return 0;

  if (prev != -1 && dp[index][prev] != -1)
    return dp[index][prev];

  ll notPick = fn(index + 1, prev, d, nums, dp);
  ll pick = nums[index][1] + fn(index + 1, (prev == -1 ? index : prev), d, nums, dp);

  if (prev != -1)
    dp[index][prev] = max(pick, notPick);

  return max(pick, notPick);
}

int main()
{
  int n, d;
  cin >> n >> d;
  vector<vector<int>> nums(n, vector<int>(2)); // money, friendship factor
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i][0] >> nums[i][1];
  }
  sort(nums.begin(), nums.end());

  ll ans = fn(0, -1, d, nums, dp);
  cout << ans << endl;

  return 0;
}