// https://codeforces.com/problemset/problem/977/A
// Wrong Subtraction
// Codeforces 977A -> Wrong Subtraction

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  while (k--)
  {
    string input = to_string(n);
    if (input.back() == '0')
    {
      input.pop_back();
      n = stoi(input);
    }
    else
    {
      n--;
    }
  }

  cout << n << endl;

  return 0;
}