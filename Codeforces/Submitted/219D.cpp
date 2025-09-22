// https://codeforces.com/contest/219/problem/D
// Choosing Capital for Treeland

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  if (!(cin >> n))
    return 0;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
  }

  // BFS from node 1 to compute initial reversals for root = 1
  vector<int> vis(n + 1, 0);
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  int initialReversals = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto &pr : adj[u])
    {
      int v = pr.first, w = pr.second;
      if (!vis[v])
      {
        vis[v] = 1;
        q.push(v);
        initialReversals += w;
      }
    }
  }

  // Reroot: compute answer for every node using relation ans[v] = ans[u] + (1 - 2*w)
  vector<int> ans(n + 1, 0);
  ans[1] = initialReversals;
  fill(vis.begin(), vis.end(), 0);
  q.push(1);
  vis[1] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto &pr : adj[u])
    {
      int v = pr.first, w = pr.second;
      if (!vis[v])
      {
        vis[v] = 1;
        ans[v] = ans[u] + (1 - 2 * w);
        q.push(v);
      }
    }
  }

  int mn = INT_MAX;
  for (int i = 1; i <= n; ++i)
    mn = min(mn, ans[i]);

  cout << mn << '\n';
  bool first = true;
  for (int i = 1; i <= n; ++i)
  {
    if (ans[i] == mn)
    {
      if (!first)
        cout << ' ';
      cout << i;
      first = false;
    }
  }
  cout << '\n';
  return 0;
}
