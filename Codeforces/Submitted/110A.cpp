// https://codeforces.com/problemset/problem/110/A
// Nearly Lucky Number

#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{

  ll num;
  cin >> num;

  int count = 0;
  string input = to_string(num);
  for (auto it : input)
  {
    if (it == '4' || it == '7')
    {
      count++;
    }
  }

  if (count == 4 || count == 7)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}