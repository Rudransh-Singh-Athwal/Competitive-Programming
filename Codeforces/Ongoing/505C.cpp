// https://codeforces.com/contest/505/problem/C
// Mr. Kitayuta, the Treasure Hunter
// Codeforces 505C -> Mr. Kitayuta, the Treasure Hunter

// QUESTION: WHAT SHOULD BE THE SIZE OF DP ARRAY DURING INITIALIZATION
// USING MAP AS DP IS GIVING TLE ON SUBMISSION

#include <bits/stdc++.h>
using namespace std;

int fn(int island, int jump, const int lastIsland, unordered_map<int, int> &diamonds, unordered_map<int, unordered_map<int, int>> &dp)
{
  if (island > lastIsland || island < 0 || jump <= 0)
    return 0;

  if (dp.count(island) && dp[island].count(jump))
    return dp[island][jump];

  int diamondsFound = (diamonds.find(island) != diamonds.end()) ? diamonds[island] : 0;

  int x = fn(island + jump - 1, jump - 1, lastIsland, diamonds, dp);
  int y = fn(island + jump, jump, lastIsland, diamonds, dp);
  int z = fn(island + jump + 1, jump + 1, lastIsland, diamonds, dp);

  return dp[island][jump] = diamondsFound + max(x, max(y, z));
}

int main()
{
  int n, k;
  cin >> n >> k;
  int lastIsland = 0;

  unordered_map<int, unordered_map<int, int>> dp;

  unordered_map<int, int> diamonds;
  diamonds[0] = 0;
  for (int i = 0; i < n; i++)
  {
    int island;
    cin >> island;
    if (diamonds.find(island) == diamonds.end())
    {
      diamonds[island] = 1;
    }
    else
    {
      diamonds[island]++;
    }

    lastIsland = max(island, lastIsland);
  }

  int maxDiamondsCollected = fn(k, k, lastIsland, diamonds, dp);
  cout << maxDiamondsCollected << endl;

  return 0;
}