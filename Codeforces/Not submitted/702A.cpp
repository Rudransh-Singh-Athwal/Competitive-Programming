// https://codeforces.com/problemset/problem/702/A
// Maximum Increase
// Codeforces 702A -> Maximum Increase

#include <bits/stdc++.h>
using namespace std;

void maximumIncreasingSubarray(vector<int> nums)
{
  int n = nums.size();
  int i = 0, j = 1;
  int maxLength = 1;
  int comp = nums[0];

  while (j < n)
  {
    if (nums[j] > comp)
    {
      comp = nums[j];
      maxLength = max(maxLength, j - i + 1);
    }
    else
    {
      i = j;
      comp = nums[i];
    }
    j++;
  }

  cout << maxLength << endl;
}

int main()
{
  int n; // size of the array
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    nums[i] = input;
  }

  maximumIncreasingSubarray(nums);

  return 0;
}