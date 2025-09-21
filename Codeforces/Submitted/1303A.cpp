// https://codeforces.com/problemset/problem/1303/A
// Erasing Zeroes

#include <bits/stdc++.h>
using namespace std;

void findMinZeroesToErase(string s)
{
  int n = s.length();
  int firstOccurence = -1, lastOccurence = -1;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      firstOccurence = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == '1')
    {
      lastOccurence = i;
      break;
    }
  }

  for (int i = firstOccurence; i < lastOccurence; i++)
  {
    if (s[i] == '0')
      count++;
  }

  cout << count << endl;
}

int main()
{
  int n;
  cin >> n;

  vector<string> vec;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    vec.push_back(s);
  }

  for (auto str : vec)
  {
    findMinZeroesToErase(str);
  }

  return 0;
}