// https://codeforces.com/contest/577/problem/B
// Modulo Sum
// Codeforces 577B -> Modulo Sum

#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool fn(int index, ll sum, const int &div, vector<int> &nums, unordered_map<int, unordered_map<ll, bool>> &dp)
{
  if (sum != 0 && sum % div == 0)
    return true;
  if (index == 0)
    return false;
  if (nums[index - 1] == 0)
    return true;

  if (dp.count(index) && dp[index].count(sum))
    return dp[index][sum];

  bool notPick = fn(index - 1, sum, div, nums, dp);
  bool pick = fn(index - 1, sum + nums[index - 1], div, nums, dp);

  return dp[index][sum] = pick || notPick;
}

int main()
{
  int n, divisor;
  cin >> n >> divisor;
  vector<int> nums;

  unordered_map<int, unordered_map<ll, bool>> dp;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums.push_back(x);
  }

  bool isPossible = fn(n, 0, divisor, nums, dp);
  if (isPossible == true)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}