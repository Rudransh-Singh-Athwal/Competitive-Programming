// https://codeforces.com/problemset/problem/467/A
// George and Accommodation
// Codeforces 467A -> George and Accommodation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y - x >= 2)
            ans++;
    }
    cout << ans << endl;

    return 0;
}