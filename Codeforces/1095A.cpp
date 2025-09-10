// https://codeforces.com/problemset/problem/1095/A
// Repeating Cipher

#include <bits/stdc++.h>
using namespace std;

void decrypt(string s, int n)
{
  int len = 1;
  string output = "";
  int i = 0;
  while (i < n)
  {
    output += s[i];
    i += len;
    len++;
  }

  cout << output << endl;
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  decrypt(s, n);

  return 0;
}