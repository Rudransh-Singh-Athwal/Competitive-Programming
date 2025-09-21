// https://codeforces.com/problemset/problem/791/A
// Bear and Big Brother

#include <bits/stdc++.h>
using namespace std;

void fn(int &a, int &b, int years)
{
  while (true)
  {
    if (a > b)
    {
      cout << years << endl;
      return;
    }
    years++;
    a *= 3;
    b *= 2;
  }
}

int main()
{
  int a, b;
  cin >> a >> b;

  fn(a, b, 0);

  return 0;
}