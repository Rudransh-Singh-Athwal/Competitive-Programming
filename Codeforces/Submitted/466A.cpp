// https://codeforces.com/problemset/problem/466/A
// Cheap Travel

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b;
  int price = 0, rem = 0;
  cin >> n >> m >> a >> b;

  if (m * a < b)
  {
    cout << n * a << "\n";
    return 0;
  }

  price += ((n / m) * b);
  rem = n % m;

  if (rem * a < b)
    price += (rem * a);
  else
    price += b;

  cout << price << "\n";

  return 0;
}