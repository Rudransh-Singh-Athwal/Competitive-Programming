// https://codeforces.com/problemset/problem/231/A
// Team

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;

    if ((x == 1 && y == 1) || (x == 1 && z == 1) || (y == 1 && z == 1) || x == 1 && y == 1 && z == 1)
      ans++;
  }

  cout << ans << endl;

  return 0;
}