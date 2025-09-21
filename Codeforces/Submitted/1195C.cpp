// https://codeforces.com/problemset/problem/1195/C
// Basketball Exercise

#define ll long long
#include <bits/stdc++.h>
using namespace std;

// ll fn(int index, vector<int> &nums1, vector<int> &nums2, bool selectedRow, vector<vector<ll>> &dp)
// {
//   if (index >= nums1.size())
//     return 0;

//   if (dp[index][selectedRow] != -1)
//     return dp[index][selectedRow];

//   ll notPick = fn(index + 1, nums1, nums2, selectedRow, dp);
//   ll pick = 0;
//   if (selectedRow)
//   {
//     pick = nums1[index] + fn(index + 1, nums1, nums2, !selectedRow, dp);
//   }
//   else
//   {
//     pick = nums2[index] + fn(index + 1, nums1, nums2, !selectedRow, dp);
//   }

//   return dp[index][selectedRow] = max(pick, notPick);
// }

int main()
{
  int n;
  cin >> n;
  vector<int> nums1;
  vector<int> nums2;
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

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

  for (int index = n - 1; index >= 0; index--)
  {
    for (int selectedRow = 0; selectedRow <= 1; selectedRow++)
    {
      ll notPick = dp[index + 1][selectedRow];
      ll pick = 0;
      if (selectedRow)
      {
        pick = nums1[index] + dp[index + 1][!selectedRow];
      }
      else
      {
        pick = nums2[index] + dp[index + 1][!selectedRow];
      }

      dp[index][selectedRow] = max(pick, notPick);
    }
  }

  ll startFromRow1 = dp[0][true];
  ll startFromRow2 = dp[0][false];

  ll ans = max(startFromRow1, startFromRow2);
  cout << ans << endl;

  return 0;
}