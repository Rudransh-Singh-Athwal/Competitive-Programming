// https://codeforces.com/problemset/problem/1/A
// Theatre Square

#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, m, a;
  if (!(cin >> n >> m >> a))
    return 0;
  long long rows = (n + a - 1) / a;
  long long cols = (m + a - 1) / a;
  cout << rows * cols << '\n';
  return 0;
}
