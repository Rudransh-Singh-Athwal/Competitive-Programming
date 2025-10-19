// https://codeforces.com/problemset/problem/1398/C
// Good Subarrays
// Codeforces 1398C -> Good Subarrays

#include <bits/stdc++.h>
using namespace std;

void fn(string str)
{
  int n = str.length();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    int j = i;
    for (j; j < n; j++)
    {
      sum += (str[j] - '0');
      if (sum == j - i + 1)
        count++;
    }
  }

  cout << count << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  vector<string> nums;
  while (t--)
  {
    int x;
    cin >> x;
    string temp;
    cin >> temp;
    nums.push_back(temp);
  }

  for (auto str : nums)
  {
    fn(str);
  }

  return 0;
}