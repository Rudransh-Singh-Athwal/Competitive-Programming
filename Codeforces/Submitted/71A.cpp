// https://codeforces.com/problemset/problem/71/A
// Way Too Long Words

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> nums;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;
    nums.push_back(input);
  }

  for (auto it : nums)
  {
    if (it.length() > 10)
    {
      cout << it[0] << it.length() - 2 << it[it.length() - 1];
    }
    else
    {
      cout << it;
    }
    cout << endl;
  }

  return 0;
}