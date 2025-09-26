// https://codeforces.com/problemset/problem/1501/B
// Napoleon Cake
// Codeforces 1501B -> Napoleon Cake

#include <bits/stdc++.h>
using namespace std;

void printMap(const unordered_map<int, bool> mp, const int n)
{
  for (int i = 0; i < n; i++)
  {
    if (mp.count(i))
    {
      cout << 1 << " ";
    }
    else
    {
      cout << 0 << " ";
    }
  }
  cout << endl;
}

void fn(const vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, bool> mp;
  for (int i = 0; i < n; i++)
  {
    int layersDrenched = nums[i];
    for (int j = i; j > max(-1, i - layersDrenched); j--)
    {
      if (mp.find(j) == mp.end())
        mp[j] = true;
    }
  }

  printMap(mp, n);
}

int main()
{
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
    fn(vec);
  }

  return 0;
}