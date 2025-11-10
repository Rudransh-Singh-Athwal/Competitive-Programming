// https://codeforces.com/problemset/problem/344/A
// Magnets
// Codeforces 344A -> Magnets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int ans = 1;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] != nums[i])
            ans++;
    }

    cout << ans << endl;

    return 0;
}