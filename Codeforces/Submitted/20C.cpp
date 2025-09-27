// https://codeforces.com/contest/20/problem/C
// Dijkstra?

#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>> &adjList, vector<int> &parent, vector<int> &dist, vector<bool> &vis)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, node
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty())
  {
    int currentDistance = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (vis[u] == true)
      continue;
    vis[u] = true;

    for (auto edge : adjList[u])
    {
      int v = edge.first;
      int weight = edge.second;
      if (!vis[v] && currentDistance + weight < dist[v])
      {
        dist[v] = currentDistance + weight;
        pq.push({dist[v], v});
        parent[v] = u;
      }
    }
  }

  return;
}

void printPath(int node, vector<int> &parent)
{
  if (parent[node] != -1)
    printPath(parent[node], parent);
  cout << node << " ";
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adjList(n + 1); // node1 -> {node2, weight}
  vector<int> parent(n + 1, -1);
  vector<int> dist(n + 1, INT_MAX);
  vector<bool> vis(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
  }

  dijkstra(1, adjList, parent, dist, vis);
  if (dist[n] == INT_MAX)
  {
    cout << -1 << endl;
    return 0;
  }
  printPath(n, parent);

  return 0;
}