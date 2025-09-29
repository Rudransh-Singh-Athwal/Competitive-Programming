// https://codeforces.com/contest/986/problem/A
// Fair

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> goods(n + 1, -1);
  vector<vector<int>> adjList(n + 1);
  vector<vector<int>> dist(k + 1, vector<int>(n + 1, INT_MAX));

  // input: type of goods at each city
  for (int i = 1; i <= n; i++)
    cin >> goods[i];

  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  // For each good type t, run multi-source BFS from all cities having that good.
  for (int t = 1; t <= k; t++)
  {
    queue<int> q;
    for (int city = 1; city <= n; city++)
    {
      if (goods[city] == t)
      {
        dist[t][city] = 0;
        q.push(city);
      }
    }

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (int v : adjList[u])
      {
        if (dist[t][v] == INT_MAX)
        {
          dist[t][v] = dist[t][u] + 1;
          q.push(v);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    vector<int> dists(k + 1, INT_MAX);
    for (int t = 1; t <= k; t++)
    {
      dists[t] = dist[t][i];
    }
    sort(dists.begin(), dists.end());

    long long cost = 0;
    for (int j = 0; j < s; j++)
    {
      cost += dists[j];
    }
    cout << cost << " ";
  }
  cout << "\n";

  return 0;
}