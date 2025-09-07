// https://codeforces.com/problemset/problem/1141/A
// Game 23

#include <bits/stdc++.h>
using namespace std;

void primeFactorization(int start, int target)
{
  if (target % start != 0)
  {
    cout << -1 << endl;
    return;
  }

  long long rem = target / start;
  int count = 0;

  while (rem % 2 == 0)
  {
    rem /= 2;
    count++;
  }

  while (rem % 3 == 0)
  {
    rem /= 3;
    count++;
  }

  if (rem != 1)
    cout << -1 << endl;
  else
    cout << count << endl;
}

int main()
{
  int n, m;
  cin >> n >> m;

  primeFactorization(n, m);

  return 0;
}