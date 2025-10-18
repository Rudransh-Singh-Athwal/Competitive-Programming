// https://codeforces.com/problemset/problem/550/C
// Divisibility by Eight

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  if (!(cin >> s))
    return 0;

  for (int i = 0; i < (int)s.size(); i++)
  {
    int d = s[i] - '0';
    if (d % 8 == 0)
    {
      cout << "YES\n"
           << d << "\n";
      return 0;
    }
  }

  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
      continue;
    for (int j = i + 1; j < n; j++)
    {
      int val = (s[i] - '0') * 10 + (s[j] - '0');
      if (val % 8 == 0)
      {
        cout << "YES\n"
             << s[i] << s[j] << "\n";
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
      continue;
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        int val = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
        if (val % 8 == 0)
        {
          cout << "YES\n"
               << s[i] << s[j] << s[k] << "\n";
          return 0;
        }
      }
    }
  }

  cout << "NO\n";
  return 0;
}
