#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> nums)
{
  int n = nums.size();
  bool even = false, odd = false;
  for (auto it : nums)
  {
    if (it & 1)
      odd = true;
    else
      even = true;
  }
  if (even && odd)
    sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++)
  {
    if (i)
      cout << " ";
    cout << nums[i];
  }
  cout << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  vector<vector<int>> nums(t);

  for (int iter = 0; iter < t; iter++)
  {
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
      cin >> temp[i];

    nums[iter] = temp;
  }

  for (auto it : nums)
  {
    fn(it);
  }

  return 0;
}