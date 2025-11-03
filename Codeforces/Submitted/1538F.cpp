// https://codeforces.com/problemset/problem/1538/F
// Interesting Function

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(int l, int r, vector<ll> &res)
{
    ll ans = r - l;
    for (int i = 10; i <= r; i *= 10)
    {
        ans += (r / i) - (l / i);
    }

    res.push_back(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<ll> res;

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        fn(l, r, res);
    }

    for (auto it : res)
    {
        cout << it << "\n";
    }

    return 0;
}