// https://codeforces.com/problemset/problem/580/B
// Kefa and Company
// Codeforces 580B -> Kefa and Company

#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<vector<int>> nums(n, vector<int>(2)); // money, friendship factor
  vector<ll> nextDPVector(n + 1, 0);
  vector<ll> curr(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i][0] >> nums[i][1];
  }
  sort(nums.begin(), nums.end());

  for (int index = n - 1; index >= 0; index--)
  {
    for (int prevIndex = 0; prevIndex <= n; prevIndex++)
    {
      int prev = prevIndex - 1;

      if (prev != -1 && nums[index][0] - nums[prev][0] >= d)
      {
        curr[prevIndex] = 0;
        continue;
      }

      ll notPick = nextDPVector[prevIndex];

      int newPrev = prev == -1 ? index : prev;
      int newPrevIndex = newPrev + 1;
      ll pick = nums[index][1] + nextDPVector[newPrevIndex];

      curr[prevIndex] = max(pick, notPick);
    }
    nextDPVector = curr;
  }

  ll ans = nextDPVector[0];
  cout << ans << endl;

  return 0;
}