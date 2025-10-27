// https://codeforces.com/problemset/problem/1526/C1
// Potions (Easy Version)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> nums(n);
  priority_queue<int, vector<int>, greater<int>> pq;
  ll health = 0;

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  for (auto it : nums)
  {
    health += it;
    pq.push(it);
    while (health < 0)
    {
      health -= pq.top();
      pq.pop();
    }
  }

  cout << pq.size() << "\n";

  return 0;
}