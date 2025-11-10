// https://codeforces.com/problemset/problem/486/A
// Calculating Function
// Codeforces 486A -> Calculating Function

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n))
        return 0;

    if (n & 1)
        cout << -((n + 1) / 2) << '\n';
    else
        cout << n / 2 << '\n';

    return 0;
}
