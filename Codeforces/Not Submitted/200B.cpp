// https://codeforces.com/problemset/problem/200/B
// Drinks
// Codeforces 200B -> Drinks

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        sum += (double)x;
    }

    double ans = (sum / n);
    cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}