// https://codeforces.com/problemset/problem/165/B
// Burning Midnight Oil

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool fn(int num, int target, int k)
{
    ll sum = num;
    while (num > 0)
    {
        num /= k;
        sum += num;
        if (sum >= target)
            return true;
    }

    return sum >= target;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    int ans = INT_MAX;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        if (fn(mid, n, k))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}