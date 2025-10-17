// https://codeforces.com/contest/2162/problem/A
// Beautiful Average

#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> &nums)
{
  int n = nums.size();
  float maxi = -1;
  for (int i = 0; i < n; i++)
  {
    float avg = 0;
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      avg = (float)sum / (j - i + 1);
      maxi = max(maxi, avg);
    }
  }

  cout << maxi << endl;
}

int main()
{
  int t;
  cin >> t;
  vector<vector<int>> nums;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
      cin >> temp[i];
    }

    nums.push_back(temp);
  }

  for (auto it : nums)
  {
    fn(it);
  }

  return 0;
}