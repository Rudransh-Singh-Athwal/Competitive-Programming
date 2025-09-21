// https://codeforces.com/problemset/problem/500/A
// New Year Transportation

#include <bits/stdc++.h>
using namespace std;

bool fn(const int target, vector<int> &nums)
{
  int index = 1;
  while (true)
  {
    if (index == target)
      return true;
    if (index > target)
      break;
    index += nums[index];
  }
  return false;
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums(n, -1);
  for (int i = 1; i < n; i++)
  {
    cin >> nums[i];
  }

  bool ok = fn(target, nums);
  if (ok == true)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}