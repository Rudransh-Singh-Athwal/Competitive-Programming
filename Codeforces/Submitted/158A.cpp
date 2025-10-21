// https://codeforces.com/problemset/problem/158/A
// Next Round

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  k--;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  if (nums[k] <= 0)
  {
    while (k > 0 && nums[k - 1] <= 0)
      k--;
    cout << k << endl;
    return 0;
  }

  while (k < nums.size() && nums[k + 1] == nums[k])
    k++;

  cout << k + 1 << endl;

  return 0;
}