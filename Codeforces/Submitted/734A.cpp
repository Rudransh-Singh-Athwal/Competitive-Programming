// https://codeforces.com/problemset/problem/734/A
// Anton and Danik

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> nums(2, 0);
    for (auto ch : str)
    {
        if (ch == 'A')
            nums[0]++;
        else
            nums[1]++;
    }

    if (nums[0] > nums[1])
        cout << "Anton\n";
    else if (nums[0] < nums[1])
        cout << "Danik\n";
    else
        cout << "Friendship\n";

    return 0;
}