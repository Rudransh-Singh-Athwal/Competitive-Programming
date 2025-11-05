// https://codeforces.com/problemset/problem/617/A
// Elephant

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << ((n % 5 == 0) ? (n / 5) : ((n / 5) + 1)) << "\n";

    return 0;
}