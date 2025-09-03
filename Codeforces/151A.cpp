// https://codeforces.com/problemset/problem/151/A
// Soft Drinking

#include <bits/stdc++.h>
using namespace std;

void toastsByEachFriend(int n, int k, int l, int c, int d, int p, int nl, int np)
{
  int totalDrink = k * l;
  int totalLemonSlices = c * d;

  int toastsLimitedByDrinks = totalDrink / (nl * n);
  int toastsLimitedBySalt = p / (np * n);
  int toastsLimitedByLime = totalLemonSlices / n;

  int toastsByEach = min(toastsLimitedByDrinks, min(toastsLimitedBySalt, toastsLimitedByLime));
  cout << toastsByEach << endl;
  return;
}

int main()
{
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  toastsByEachFriend(n, k, l, c, d, p, nl, np);

  return 0;
}