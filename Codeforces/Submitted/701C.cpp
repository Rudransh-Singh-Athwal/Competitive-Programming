// https://codeforces.com/problemset/problem/701/C
// They Are Everywhere

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string str;
    vector<int> total(256, 0), freq(256, 0);
    int need = 0, formed = 0, left = 0;

    cin >> n >> str;
    int best = n;

    for (auto ch : str)
        if (total[(unsigned char)ch]++ == 0)
            need++;

    for (int right = 0; right < n; right++)
    {
        if (freq[(unsigned char)str[right]]++ == 0)
            formed++;
        while (formed == need)
        {
            best = min(best, right - left + 1);
            if (--freq[(unsigned char)str[left]] == 0)
                formed--;
            left++;
        }
    }

    cout << best << "\n";

    return 0;
}