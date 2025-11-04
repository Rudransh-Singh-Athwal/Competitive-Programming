// https://codeforces.com/problemset/problem/126/B
// Password
// Codeforces 126B -> Password

#include <bits/stdc++.h>
using namespace std;

void findStringsCommonToPrefixAndSuffix(string str, vector<string> &nums)
{
    int n = str.length();
    string prefix = "";
    string suffix = "";
    for (int i = 0; i < n - 1; i++)
    {
        prefix += str[i];
        suffix = str.substr(n - prefix.length(), prefix.length());
        if (prefix == suffix)
            nums.push_back(prefix);
    }

    sort(nums.begin(), nums.end(), [](string a, string b)
         { return a.length() > b.length(); });
}

bool findStringInMiddle(string str, string target)
{
    for (int i = 1; i < str.length() - target.length(); i++)
    {
        string sub = str.substr(i, target.length());
        if (sub == target)
            return true;
    }

    return false;
}

void printVector(vector<string> &nums)
{
    for (auto it : nums)
        cout << it << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    // strings that exist at both prefix and suffix
    vector<string> nums;
    findStringsCommonToPrefixAndSuffix(input, nums);

    // cout << endl;
    // printVector(nums);
    // cout << endl;

    string password = "-1";
    for (auto str : nums)
    {
        if (findStringInMiddle(input, str))
        {
            password = str;
            break;
        }
    }

    if (password != "-1")
    {
        cout << password << "\n";
    }
    else
    {
        cout << "Just a legend\n";
    }

    return 0;
}