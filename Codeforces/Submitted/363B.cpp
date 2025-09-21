// https://codeforces.com/problemset/problem/363/B
// Fence

#include <bits/stdc++.h>
using namespace std;

int findMinHeightFence(int n, int k, vector<int> &height)
{
  int sum = 0;
  int l = 0, r = k;
  for (int i = 0; i < k; i++)
  {
    sum += height[i];
  }

  int minSum = sum;
  int minStart = 0;

  while (r < n)
  {
    sum -= height[l++];
    sum += height[r++];
    if (sum < minSum)
    {
      minSum = sum;
      minStart = l;
    }
  }

  return minStart + 1;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> height;
  for (int i = 0; i < n; i++)
  {
    int h;
    cin >> h;
    height.push_back(h);
  }

  int ans = findMinHeightFence(n, k, height);

  cout << ans << endl;

  return 0;
}