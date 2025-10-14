// https://codeforces.com/problemset/problem/1703/A
// YES or YES

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> nums;
  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;
    nums.push_back(input);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if ((nums[i][0] == 'y' || nums[i][0] == 'Y') && (nums[i][1] == 'e' || nums[i][1] == 'E') && (nums[i][2] == 's' || nums[i][2] == 'S'))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}