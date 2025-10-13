// https://codeforces.com/problemset/problem/136/A
// Presents

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_map<int, int> mp;

  for (int i = 1; i <= n; i++)
  {
    int input;
    cin >> input;
    mp[input] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    cout << mp[i] << " ";
  }
  cout << endl;

  return 0;
}