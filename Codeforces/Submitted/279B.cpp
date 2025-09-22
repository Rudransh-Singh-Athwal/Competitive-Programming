// https://codeforces.com/problemset/problem/279/B
// Books

#include <bits/stdc++.h>
using namespace std;

int maxBooksRead(vector<int> &nums, const int &totalTime)
{
  int n = nums.size();
  int i = 0, j = 0, timeSpent = 0, maxBooks = 0;
  while (j < n)
  {
    if ((nums[j] + timeSpent) <= totalTime)
    {
      timeSpent += nums[j];
      j++;
    }
    else
    {
      timeSpent -= nums[i];
      i++;
    }
    maxBooks = max(maxBooks, j - i);
  }

  return maxBooks;
}

int main()
{
  int n, time;
  cin >> n >> time;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  int maxBooks = maxBooksRead(nums, time);
  cout << maxBooks << endl;

  return 0;
}