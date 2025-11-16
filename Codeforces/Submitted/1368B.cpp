// https://codeforces.com/problemset/problem/1368/B
// Codeforces Subsequences

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long k;
    cin >> k;
    string base = "codeforces";
    vector<unsigned long long> count(10, 1);
    unsigned long long prod = 1;

    int index = 0;
    while (prod < ((unsigned long long)k))
    {
        prod = (prod / count[index]) * (count[index] + 1);
        count[index]++;
        index = (index + 1) % 10;
    }

    string ans;
    for (int i = 0; i < 10; i++)
    {
        ans.append(count[i], base[i]);
    }

    cout << ans << "\n";

    return 0;
}