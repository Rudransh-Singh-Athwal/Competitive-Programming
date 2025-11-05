// https://codeforces.com/problemset/problem/466/C
// Number of Ways

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fn(vector<int> &nums, ll sum)
{
    int n = nums.size();
    ll target = sum / 3, countPrefixEqualTarget = 0, ways = 0, currSum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        currSum += nums[i];

        if (currSum == 2 * target)
            ways += countPrefixEqualTarget;

        if (currSum == target)
            countPrefixEqualTarget++;
    }

    return ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 3 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    ll ways = fn(nums, sum);
    cout << ways << "\n";

    return 0;
}