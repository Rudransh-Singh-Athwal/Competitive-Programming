#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> nums(n, vector<int>(4));
  for (int i = 0; i < n; i++)
  {
    int a, b, c, d;
    cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
  }

  for (int i = 0; i < n; i++)
  {
    if ((nums[i][0] == nums[i][1]) && (nums[i][0] == nums[i][2]) && (nums[i][0] == nums[i][3]))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}