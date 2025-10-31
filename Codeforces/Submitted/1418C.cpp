// https://codeforces.com/problemset/problem/1418/C
// Mortal Kombat Tower

#include <bits/stdc++.h>
using namespace std;

int fn(vector<int> &nums)
{
    int n = nums.size(), points = 0;

    if (nums[0] == 1)
    {
        points++;
    }

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == 0)
        {
            continue;
        }
        int j = i;
        while (j < n && nums[j] == 1)
            j++;
        points += (j - i) / 3;
        i = j - 1;
    }

    return points;
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> nums;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        nums.push_back(temp);
    }

    for (auto num : nums)
    {
        cout << fn(num) << "\n";
    }

    return 0;
}