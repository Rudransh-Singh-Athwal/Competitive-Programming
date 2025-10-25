// https://codeforces.com/problemset/problem/1542/B
// Plus and Multiply

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(vector<int> &nums)
{
  ll target = nums[0], a = nums[1], b = nums[2]; // multiply a, add b
  if (target == 1)
  {
    cout << "Yes\n";
    return;
  }

  // handle b==0 (only multiplication by a)
  if (b == 0)
  {
    ll curr = 1;
    while (curr <= target)
    {
      if (curr == target)
      {
        cout << "Yes\n";
        return;
      }
      if (a == 1)
        break;
      if ((curr * a) > target)
        break;
      curr *= a;
    }
    cout << "No\n";
    return;
  }

  // handle a == 1 (only adds effectively)
  if (a == 1)
  {
    if ((target - 1) % b == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
    return;
  }

  ll curr = 1;
  while (curr <= target)
  {
    if ((target - curr) % b == 0)
    {
      cout << "Yes\n";
      return;
    }
    if ((curr * a) > target)
      break; // next multiplication would overflow or exceed target
    curr *= a;
  }

  cout << "No\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> nums(n, vector<int>(3));

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
  }

  for (auto num : nums)
  {
    fn(num);
  }

  return 0;
}