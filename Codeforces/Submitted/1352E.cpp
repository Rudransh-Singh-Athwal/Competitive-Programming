// https://codeforces.com/problemset/problem/1352/E
// Special Elements

#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> &nums, vector<int> &res)
{
    int n = nums.size();
    vector<int> count(n + 1, 0);
    for (int x : nums)
        if (x <= n)
            count[x]++;

    vector<char> seen(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];
            if (sum > n)
                break;
            if (!seen[sum])
            {
                ans += count[sum];
                seen[sum] = 1;
            }
        }
    }

    res.push_back(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> res;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        fn(nums, res);
    }

    for (auto x : res)
        cout << x << "\n";

    return 0;
}