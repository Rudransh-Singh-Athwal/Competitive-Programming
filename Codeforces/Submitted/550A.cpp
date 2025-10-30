// https://codeforces.com/problemset/problem/550/A
// Two Substrings

#include <bits/stdc++.h>
using namespace std;

bool containsSubstrings(string str)
{
  int n = str.length();
  int i = 0;
  bool ab = 0, ba = 0;
  int conflict = 0;

  while (i < n - 1)
  {
    if (str[i] == 'A' && str[i + 1] == 'B')
    {
      if (i + 2 < n && str[i + 2] == 'A')
      {
        conflict++;
        i += 2;
      }
      else
      {
        ab = true;
        i++;
      }
    }
    else if (str[i] == 'B' && str[i + 1] == 'A')
    {
      if (i + 2 < n && str[i + 2] == 'B')
      {
        conflict++;
        i += 2;
      }
      else
      {
        ba = true;
        i++;
      }
    }
    i++;
  }

  return ((conflict >= 2) || (ab && ba) || (conflict > 0 && (ab || ba)));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  if (containsSubstrings(str))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}