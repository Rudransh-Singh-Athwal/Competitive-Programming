// https://codeforces.com/contest/2171/problem/A

#include <bits/stdc++.h>
using namespace std;

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
        if (n & 1)
        {
            res.push_back(0);
            continue;
        }
        int i = 0, count = 0;

        while (4 * i <= n)
        {
            count++;
            i++;
        }
        res.push_back(count);
    }

    for (auto count : res)
        cout << count << "\n";

    return 0;
}