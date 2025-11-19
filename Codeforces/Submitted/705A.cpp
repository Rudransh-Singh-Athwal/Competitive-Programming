// https://codeforces.com/problemset/problem/705/A
// Hulk

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string even = "that I love";
    string odd = "that I hate";
    string ans = "I hate";

    for (int i = 2; i <= n; i++)
    {
        ans += ' ';
        if (i & 1)
        {
            ans += odd;
        }
        else
        {
            ans += even;
        }
    }

    ans += " it";
    cout << ans << "\n";

    return 0;
}