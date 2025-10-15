// https://codeforces.com/problemset/problem/479/C
// Exams

#include <bits/stdc++.h>
using namespace std;

void fn(vector<vector<int>> &nums)
{
  int lastDay = -1;

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i][1] >= lastDay)
    {
      lastDay = nums[i][1];
    }
    else
    {
      lastDay = max(lastDay, nums[i][0]);
    }
  }

  cout << lastDay << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> nums(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i][0];
    cin >> nums[i][1];
  }
  sort(nums.begin(), nums.end());

  fn(nums);

  return 0;
}