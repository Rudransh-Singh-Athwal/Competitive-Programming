// https://codeforces.com/problemset/problem/112/A
// Petya and Strings

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    for (auto &ch : s1)
    {
        ch = tolower(ch);
    }
    for (auto &ch : s2)
    {
        ch = tolower(ch);
    }

    if (s1 < s2)
        cout << -1 << "\n";
    else if (s2 < s1)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}