// https://codeforces.com/problemset/problem/1350/B
// Orac and Models
// Codeforces 1350B -> Orac and Models

#include <bits/stdc++.h>
using namespace std;

int fn(int index, int dividend, vector<int> &nums)
{
  if (index == 0)
    return 0;

  int notPick = fn(index - 1, dividend, nums);
  int pick = 0;
  if ((dividend == -1) || (dividend % nums[index - 1] == 0))
  {
    pick = 1 + fn(index - 1, nums[index - 1], nums);
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
    int m;
    cin >> m;
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    input.push_back(temp);
  }

  for (auto vec : input)
  {
    int ans = fn(vec.size(), -1, vec);
    cout << ans << endl;
  }

  return 0;
}