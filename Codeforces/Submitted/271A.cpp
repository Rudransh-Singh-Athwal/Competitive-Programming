// https://codeforces.com/problemset/problem/271/A
// Beautiful Year

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    cin >> year;

    while (1)
    {
        year++;
        string y = to_string(year);
        vector<int> freq(10, 0);
        bool distinct = true;
        for (char ch : y)
        {
            if (++freq[ch - '0'] > 1)
            {
                distinct = false;
                break;
            }
        }
        if (distinct)
        {
            cout << year << "\n";
            return 0;
        }
    }

    return 0;
}