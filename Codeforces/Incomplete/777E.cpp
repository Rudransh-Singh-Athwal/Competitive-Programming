// https://codeforces.com/contest/777/problem/E
// Hanoi Factory
// Codeforces 777E -> Hanoi Factory

#include <bits/stdc++.h>
using namespace std;

bool customComparatorForOuterRadius(vector<int> &nums)
{
  return nums[1] > nums[1];
}

int fn(int index, int prevInnerRadius, int prevOuterRadius, vector<vector<int>> &nums)
{
  if (index >= nums.size())
    return 0;

  int notPick = fn(index + 1, prevInnerRadius, prevOuterRadius, nums);

  int pick = 0;
  int innerRadius = nums[index][0];
  int outerRadius = nums[index][1];
  int height = nums[index][2];
  if (outerRadius > prevInnerRadius && outerRadius <= prevOuterRadius)
  {
    pick = height + fn(index + 1, innerRadius, outerRadius, nums);
  }

  return max(pick, notPick);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> input;

  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    int a, b, h;
    cin >> a >> b >> h;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(h);

    input.push_back(temp);
  }

  vector<vector<int>> sortedByInnerRadius = input;
  sort(sortedByInnerRadius.begin(), sortedByInnerRadius.end());

  vector<vector<int>> sortedByOuterRadius = input;
  sort(sortedByOuterRadius.begin(), sortedByOuterRadius.end(), [](const vector<int> a, const vector<int> b)
       { return a[1] > b[1]; });

  int ans1 = fn(0, 0, 0, sortedByInnerRadius);
  int ans2 = fn(0, 0, 0, sortedByOuterRadius);
  cout << ans1 << endl;
  cout << ans2 << endl;

  return 0;
}