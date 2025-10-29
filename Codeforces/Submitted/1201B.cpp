// https://codeforces.com/problemset/problem/1201/B
// Zero Array

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int maxi = INT_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    maxi = max(maxi, x);
    sum += x;
  }

  if ((sum & 1) || (maxi > sum / 2))
  {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  return 0;
}