// https://codeforces.com/problemset/problem/339/A
// Helpful Maths

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string input;
  cin >> input;
  int n = input.length();
  vector<int> count(4, 0);

  for (int i = 0; i < n; i++)
  {
    if (input[i] == '1' || input[i] == '2' || input[i] == '3')
    {
      count[input[i] - '0']++;
    }
  }

  for (int i = 0; i < n; i += 2)
  {
    if (count[1] != 0)
    {
      input[i] = '1';
      count[1]--;
    }
    else if (count[2] != 0)
    {
      input[i] = '2';
      count[2]--;
    }
    else if (count[3] != 0)
    {
      input[i] = '3';
      count[3]--;
    }
  }

  cout << input << endl;

  return 0;
}