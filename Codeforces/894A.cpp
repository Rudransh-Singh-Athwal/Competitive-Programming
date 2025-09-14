// https://codeforces.com/problemset/problem/894/A
// QAQ
// Codeforces 894A -> QAQ

#include <bits/stdc++.h>
using namespace std;

int fn(int index, string &input, string targetString, string curr)
{
  if (curr.length() == 3)
  {
    return curr == targetString ? 1 : 0;
  }
  if (index >= input.length())
  {
    return curr == targetString ? 1 : 0;
  }

  int notPick = fn(index + 1, input, targetString, curr);
  int pick = 0;
  if (input[index] == 'Q' || input[index] == 'A')
  {
    pick = fn(index + 1, input, targetString, curr + input[index]);
  }

  return pick + notPick;
}

int main()
{
  string input;
  cin >> input;

  int ans = fn(0, input, "QAQ", "");

  cout << ans << endl;

  return 0;
}