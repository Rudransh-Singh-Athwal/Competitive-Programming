// https://codeforces.com/problemset/problem/1195/C
// Basketball Exercise
// Codeforces 1195C -> Basketball Exercise

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll fn(int index, vector<int> &nums1, vector<int> &nums2, bool selectedRow, vector<vector<ll>> &dp)
{
  if (index >= nums1.size())
    return 0;

  if (dp[index][selectedRow] != -1)
    return dp[index][selectedRow];

  ll notPick = fn(index + 1, nums1, nums2, selectedRow, dp);
  ll pick = 0;
  if (selectedRow)
  {
    pick = nums1[index] + fn(index + 1, nums1, nums2, !selectedRow, dp);
  }
  else
  {
    pick = nums2[index] + fn(index + 1, nums1, nums2, !selectedRow, dp);
  }

  return dp[index][selectedRow] = max(pick, notPick);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums1;
  vector<int> nums2;
  vector<vector<ll>> dp(n, vector<ll>(2, -1));

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums1.push_back(x);
  }
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums2.push_back(x);
  }

  ll startFromRow1 = fn(0, nums1, nums2, true, dp);
  ll startFromRow2 = fn(0, nums1, nums2, false, dp);

  ll ans = max(startFromRow1, startFromRow2);
  cout << ans << endl;

  return 0;
}