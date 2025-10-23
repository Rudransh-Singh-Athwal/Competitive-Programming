// https://codeforces.com/problemset/problem/50/A
// Domino piling

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y;
  cin >> x >> y;
  bool rem = false;
  if (x & 1 == 1)
    rem = true;

  int ans = (x / 2) * y;
  if (rem)
    ans += (y / 2);

  cout << ans << endl;

  return 0;
}