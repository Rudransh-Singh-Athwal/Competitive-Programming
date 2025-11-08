// https://codeforces.com/problemset/problem/41/A
// Translation
// Codeforces 41A -> Translation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    if (s1 == s2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}