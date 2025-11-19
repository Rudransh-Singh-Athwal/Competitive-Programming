// https://codeforces.com/problemset/problem/1328/A
// Divisibility Problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> ans;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a % b == 0)
        {
            ans.push_back(0);
            continue;
        }

        int res = b - (a % b);
        ans.push_back(res);
    }

    for (auto it : ans)
        cout << it << "\n";

    return 0;
}