// https://codeforces.com/problemset/problem/1501/B
// Napoleon Cake

#include <bits/stdc++.h>
using namespace std;

void fn(const vector<int> &nums, int n)
{
  vector<int> res(n, 0);
  int curr = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    curr = max(curr, nums[i]);
    if (curr > 0)
    {
      res[i] = 1;
      curr--;
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << res[i] << (i + 1 == n ? "\n" : " ");
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> input;

  for (int i = 0; i < n; i++)
  {
    int numberOfLayers;
    cin >> numberOfLayers;
    vector<int> amountOfCream;
    for (int j = 0; j < numberOfLayers; j++)
    {
      int x;
      cin >> x;
      amountOfCream.push_back(x);
    }
    input.push_back(amountOfCream);
  }

  for (auto vec : input)
  {
    fn(vec, vec.size());
  }

  return 0;
}