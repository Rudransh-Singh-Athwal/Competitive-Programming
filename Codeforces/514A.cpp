// https://codeforces.com/contest/514/problem/A

#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll transformNumber(ll n)
{
  ll output = 0;
  string num = to_string(n);
  for (int i = 0; i < num.length(); i++)
  {
    int temp = num[i] - '0';
    if (i == 0 && num[0] == '9')
    {
      output *= 10;
      output += temp;
      continue;
    }

    if (temp >= 5)
    {
      temp = 9 - temp;
    }
    output *= 10;
    output += temp;
  }

  return output;
}

int main()
{
  ll number;
  cin >> number;
  cout << transformNumber(number) << endl;
  return 0;
}