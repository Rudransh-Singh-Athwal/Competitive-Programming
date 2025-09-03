// https://codeforces.com/problemset/problem/144/A
// Arrival of the General

#include <bits/stdc++.h>
using namespace std;

void swapSoldiers(int n)
{
  int minHeight = INT_MAX, maxHeight = INT_MIN;
  int minIndex = -1, maxIndex = -1;
  int ans = -1;

  for (int i = 0; i < n; i++)
  {
    int height;
    cin >> height;
    if (height > maxHeight)
    {
      maxHeight = height;
      maxIndex = i;
    }
    if (height <= minHeight)
    {
      minHeight = height;
      minIndex = i;
    }
  }

  if (maxIndex < minIndex)
  {
    ans = maxIndex + (n - 1 - minIndex);
  }
  else
  {
    ans = maxIndex + (n - 1 - minIndex) - 1;
  }

  cout << ans << endl;
}

int main()
{
  int n;
  cin >> n;
  swapSoldiers(n);

  return 0;
}