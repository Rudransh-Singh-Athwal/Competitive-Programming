// https://codeforces.com/problemset/problem/59/A
// Word

#include <bits/stdc++.h>
using namespace std;

void convert(string &str, bool convertToUppercase)
{
    if (convertToUppercase)
    {
        for (auto &ch : str)
        {
            ch = toupper(ch);
        }
    }
    else
    {
        for (auto &ch : str)
        {
            ch = tolower(ch);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lower = 0, upper = 0;
    string str;
    cin >> str;
    for (auto ch : str)
    {
        if (ch >= 'a' && ch <= 'z')
            lower++;
        else
            upper++;
    }

    if (lower < upper)
    {
        convert(str, true);
    }
    else
    {
        convert(str, false);
    }

    cout << str << "\n";

    return 0;
}