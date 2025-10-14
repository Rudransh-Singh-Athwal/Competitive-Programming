// https://codeforces.com/problemset/problem/1526/B
// I Hate 1111

#include <bits/stdc++.h>
using namespace std;

/*
All larger numbers can be expressed as combinations of 11 and 111 as:
1111 = 11 × 101
11111 = 111 × 100 + 11
and so on...
*/

void fn(int num)
{
  bool possible = false;
  // Try all possible counts of 111 (from 0 up to num/111)
  for (int i = 0; i * 111 <= num; i++)
  {
    int remaining = num - i * 111;
    // Check if remaining can be formed using 11's
    if (remaining % 11 == 0)
    {
      possible = true;
      break;
    }
  }

  if (possible)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  for (auto num : nums)
  {
    fn(num);
  }

  return 0;
}