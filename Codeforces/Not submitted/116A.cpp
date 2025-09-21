// https://codeforces.com/problemset/problem/116/A
// Tram
// Codeforces 116A -> Tram

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int currentPassengers = 0;
  int minimumCapacityRequired = 0;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    currentPassengers -= a;
    currentPassengers += b;

    minimumCapacityRequired = max(minimumCapacityRequired, currentPassengers);
  }

  cout << minimumCapacityRequired << endl;

  return 0;
}