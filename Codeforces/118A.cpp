// https://codeforces.com/problemset/problem/118/A
// String Task

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
  if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
    return true;
  return false;
}

void parseString(string str)
{
  int n = str.length();
  string output = "";

  for (int i = 0; i < n; i++)
  {
    char ch = str[i];
    if (!isVowel(ch))
    {
      if (ch >= 'A' && ch <= 'Z')
      {
        ch += 32;
      }
      output += '.';
      output += ch;
    }
  }

  cout << output << endl;
}

int main()
{
  string input;
  cin >> input;

  parseString(input);

  return 0;
}