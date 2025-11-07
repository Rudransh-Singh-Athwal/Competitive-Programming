// https://codeforces.com/problemset/problem/1324/E
// Sleeping Schedule

#include <bits/stdc++.h>
using namespace std;

int fn(int index, int currTime, int hours, int left, int right, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index][currTime] != -1)
        return dp[index][currTime];

    int t1 = (currTime + nums[index]) % hours;
    int t2 = (currTime + nums[index] - 1) % hours;

    int gain1 = (left <= t1 && t1 <= right) ? 1 : 0;
    int gain2 = (left <= t2 && t2 <= right) ? 1 : 0;

    int option1 = gain1 + fn(index + 1, t1, hours, left, right, nums, dp);
    int option2 = gain2 + fn(index + 1, t2, hours, left, right, nums, dp);

    return dp[index][currTime] = max(option1, option2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, hours, left, right;
    cin >> n >> hours >> left >> right;
    vector<int> nums(n);
    vector<vector<int>> dp(n, vector<int>(hours, -1));
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = fn(0, 0, hours, left, right, nums, dp);
    cout << ans << "\n";

    return 0;
}