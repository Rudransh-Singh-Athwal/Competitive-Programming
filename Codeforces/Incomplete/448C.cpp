// https://codeforces.com/contest/448/problem/C
// Painting Fence
// Codeforces 448C -> Painting Fence

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fnLeft(vector<int> &nums)
{
  int i = 0, n = nums.size(), ref = 0;
  ll strokes = 0;

  while (i < n)
  {
    if (nums[i] > ref)
    {
      strokes += nums[i] - ref;
      ref = nums[i];
    }
    i++;
  }

  return strokes;
}

ll fnRight(vector<int> &nums)
{
  int n = nums.size(), ref = 0;
  int i = n - 1;
  ll strokes = 0;

  while (i >= 0)
  {
    if (nums[i] > ref)
    {
      strokes += nums[i] - ref;
    }
    ref = nums[i];
    i--;
  }

  return strokes;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  if (n < 2)
  {
    cout << n << endl;
    return 0;
  }

  ll strokesLeft = fnLeft(nums);
  ll strokesRight = fnRight(nums);
  // ll ans = min(strokesLeft, strokesRight);
  ll ans = strokesLeft;
  cout << ans << endl;

  return 0;
}