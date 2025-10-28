// https://codeforces.com/problemset/problem/371/C
// Hamburgers

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canMake(ll x, const vector<ll> &req, const vector<ll> &have, const vector<ll> &price, ll money)
{
  ll cost = 0;
  for (int i = 0; i < 3; i++)
  {
    ll need = (ll)req[i] * x - have[i];
    if (need > 0)
      cost += need * price[i];
    if (cost > (ll)money)
      return false;
  }

  return cost <= (ll)money;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string recipe;
  vector<ll> req(3, 0); // required bread, sausage, cheese
  vector<ll> have(3, 0);
  vector<ll> price(3, 0);
  ll money;

  // Take input
  cin >> recipe;
  for (auto ch : recipe)
  {
    if (ch == 'B')
      req[0]++;
    else if (ch == 'S')
      req[1]++;
    else
      req[2]++;
  }

  for (int i = 0; i < 3; i++)
  {
    cin >> have[i];
  }

  for (int i = 0; i < 3; i++)
  {
    cin >> price[i];
  }

  cin >> money;

  ll low = 0, high = 1e13;
  ll ans = 0;
  while (low <= high)
  {
    ll mid = low + (high - low) / 2;
    if (canMake(mid, req, have, price, money))
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  cout << ans << '\n';

  return 0;
}