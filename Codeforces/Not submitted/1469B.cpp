// https://codeforces.com/problemset/problem/1469/B
// Red and Blue
// Codeforces 1469B -> Red and Blue

#include <bits/stdc++.h>
using namespace std;

int fn(int i, int j, int maxSum, const vector<int> &red, const int n, const vector<int> &blue, const int m)
{
  if (i == n && j == m)
  {
    return maxSum;
  }

  int pickRed = 0;
  int pickBlue = 0;

  if (i < n)
  {
    pickRed = fn(i + 1, j, maxSum + red[i], red, n, blue, m);
  }

  if (j < m)
  {
    pickBlue = fn(i, j + 1, maxSum + blue[j], red, n, blue, m);
  }

  return max(maxSum, max(pickRed, pickBlue));
}

int main()
{
  int n;
  cin >> n;
  vector<vector<vector<int>>> input(n);

  for (int i = 0; i < n; i++)
  {
    vector<int> red;
    vector<int> blue;

    int blueEls;
    cin >> blueEls;
    for (int j = 0; j < blueEls; j++)
    {
      int el;
      cin >> el;
      blue.push_back(el);
    }

    int redEls;
    cin >> redEls;
    for (int j = 0; j < redEls; j++)
    {
      int el;
      cin >> el;
      red.push_back(el);
    }

    input[i].push_back(red);
    input[i].push_back(blue);
  }

  for (auto it : input)
  {
    int ans = fn(0, 0, 0, it[0], it[0].size(), it[1], it[1].size());
    cout << ans << endl;
  }

  return 0;
}