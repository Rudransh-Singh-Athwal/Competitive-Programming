// https://codeforces.com/problemset/problem/263/A
// Beautiful matrix

#include <bits/stdc++.h>
using namespace std;

void calcMinSteps(vector<vector<int>> nums)
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (nums[i][j] == 1)
      {
        int rowDiff = abs(2 - i);
        int colDiff = abs(2 - j);
        cout << rowDiff + colDiff << endl;
        return;
      }
    }
  }
}

int main()
{
  vector<vector<int>> nums(5, vector<int>(5, 0));
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int input;
      cin >> input;
      nums[i][j] = input;
    }
  }

  calcMinSteps(nums);

  return 0;
}