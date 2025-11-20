// https://codeforces.com/contest/2171/problem/C1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        int xa = 0, xb = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            xa ^= a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
            xb ^= b[i];
        }

        if (xa == xb)
        {
            cout << "Tie\n";
            continue;
        }

        int lastDiff = 0;
        for (int i = n; i >= 1; --i)
        {
            if (a[i] != b[i])
            {
                lastDiff = i;
                break;
            }
        }

        if (lastDiff == 0)
        {
            cout << "Tie\n";
            continue;
        }

        if (lastDiff % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }

    return 0;
}
