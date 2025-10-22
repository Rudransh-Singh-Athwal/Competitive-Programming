// https://codeforces.com/problemset/problem/580/B
// Kefa and Company
// Codeforces 580B -> Kefa and Company

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll fn(int index, vector<pair<int, ll>> &nums, int maxi, int mini, const int maxD, unordered_map<int, unordered_map<uint64_t, ll>> &dp)
{
  if (index < 0)
    return 0;

  uint32_t high = static_cast<uint32_t>(static_cast<int32_t>(maxi));
  uint32_t low = static_cast<uint32_t>(static_cast<int32_t>(mini));
  uint64_t key = (static_cast<uint64_t>(high) << 32) | static_cast<uint64_t>(low);

  if (dp.count(index) && dp[index].count(key))
    return dp[index][key];

  ll notPick = fn(index - 1, nums, maxi, mini, maxD, dp);

  int money = nums[index].first;
  ll friendshipFactor = nums[index].second;
  ll pick = 0;

  int newMax = (maxi == INT_MIN) ? money : max(maxi, money);
  int newMin = (mini == INT_MAX) ? money : min(mini, money);

  if ((ll)newMax - (ll)newMin <= (ll)maxD)
  {
    pick = friendshipFactor + fn(index - 1, nums, newMax, newMin, maxD, dp);
  }

  return dp[index][key] = max(pick, notPick);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, maxD;
  cin >> n >> maxD;
  vector<pair<int, ll>> nums(n);
  unordered_map<int, unordered_map<uint64_t, ll>> dp;

  for (int i = 0; i < n; i++)
  {
    int x;
    ll y;
    cin >> x >> y;
    nums[i].first = x;  // money
    nums[i].second = y; // friendship factor
  }

  cout << fn(n - 1, nums, INT_MIN, INT_MAX, maxD, dp) << "\n";

  return 0;
}