// https://codeforces.com/problemset/problem/977/F
// Consecutive Subsequence
// Codeforces 977F -> Consecutive Subsequence

#include <bits/stdc++.h>
using namespace std;

int fn(int index, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index < 0)
        return 0;

    if (prev != -1 && dp[index][prev] != -1)
        return dp[index][prev];

    int notPick = fn(index - 1, prev, nums, dp);
    int pick = 0;
    if (prev == -1 || (nums[index] == nums[prev] - 1))
    {
        pick = 1 + fn(index - 1, index, nums, dp);
    }

    if (prev != -1)
        dp[index][prev] = max(pick, notPick);

    return max(pick, notPick);
}

void reconstruct(int index, int prev, vector<int> &nums, vector<vector<int>> &dp, vector<int> &picked)
{
    if (index < 0)
        return;

    int notPick = fn(index - 1, prev, nums, dp);
    int pick = INT_MIN;
    if (prev == -1 || (nums[index] == nums[prev] - 1))
        pick = 1 + fn(index - 1, index, nums, dp);

    if (pick >= notPick)
    {
        picked.push_back(index + 1);
        reconstruct(index - 1, index, nums, dp, picked);
    }
    else
    {
        reconstruct(index - 1, prev, nums, dp, picked);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<int> picked;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = fn(n - 1, -1, nums, dp);

    reconstruct(n - 1, -1, nums, dp, picked);

    reverse(picked.begin(), picked.end());

    cout << ans << "\n";
    for (auto &el : picked)
        cout << el << " ";

    return 0;
}