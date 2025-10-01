// https://codeforces.com/contest/229/problem/B
// Planets
// Codeforces 229B -> Planets

#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &adjList, vector<bool> &vis, vector<unordered_set<int>> &prohibited, const int target)
{
  vector<int> timeTaken(target + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  timeTaken[1] = 0;

  while (!pq.empty())
  {
    auto p = pq.top();
    pq.pop();
    int t = p.first;
    int v = p.second;

    // cout << "Planet " << v << endl;

    if (vis[v] == true)
    {
      // cout << "Abort!!! Already visited...\n";
      continue;
    }
    while (v != target && prohibited[v].count(t))
      t++;

    if (pq.top().first < t)
    {
      pq.push({t, v});
      continue;
    }

    vis[v] = true;
    timeTaken[v] = min(timeTaken[v], t);
    if (v == target)
      return timeTaken[target];

    for (auto it : adjList[v])
    {
      if (vis[it.first])
        continue;
      pq.push({t + it.second, it.first});
    }
  }

  return -1;
}

int main()
{
  int planets, stargates;
  cin >> planets >> stargates;
  vector<vector<pair<int, int>>> adjList(planets + 1); // neigboring planet, time taken
  vector<unordered_set<int>> prohibited(planets + 1);
  vector<bool> vis(planets + 1, false);

  for (int i = 1; i <= stargates; i++)
  {
    int u, v, d;
    cin >> u >> v >> d;
    adjList[u].push_back({v, d});
    adjList[v].push_back({u, d});
  }
  for (int i = 1; i <= planets; i++)
  {
    int x;
    cin >> x;
    while (x > 0)
    {
      int time;
      cin >> time;
      prohibited[i].insert(time);
      x--;
    }
  }

  int timeTaken = dijkstra(adjList, vis, prohibited, planets);

  cout << timeTaken << endl;

  return 0;
}