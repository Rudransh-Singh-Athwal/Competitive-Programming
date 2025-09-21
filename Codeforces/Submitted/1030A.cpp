// https://codeforces.com/problemset/problem/1030/A
// In Search of an Easy Problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  bool isHard = false;
  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    if (input == 1)
    {
      isHard = true;
      break;
    }
  }

  if (isHard)
  {
    cout << "HARD\n";
  }
  else
  {
    cout << "EASY\n";
  }

  return 0;
}