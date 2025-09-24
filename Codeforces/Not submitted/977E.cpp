// https://codeforces.com/problemset/problem/977/E
// Cyclic Components
// Codeforces 977E -> Cyclic Components

#include <bits/stdc++.h>
using namespace std;

void dfs(int curr_node, int parent, const vector<vector<int>> &adjList, vector<bool> &vis, const int start_node, int &paths)
{
  // cout << "dfs called for " << curr_node << endl;
  vis[curr_node] = true;

  for (auto node : adjList[curr_node])
  {
    if (node != parent)
    {
      if (node == start_node)
      {
        // cout << "+1 for " << node << endl;
        paths++;
      }
      else
        dfs(node, curr_node, adjList, vis, start_node, paths);
    }
  }
}

void printVisitedNodes(vector<bool> &vis)
{
  // cout << "Visited\n";
  for (int i = 1; i <= vis.size(); i++)
  {
    if (vis[i])
    {
      cout << i << " ";
    }
  }
  cout << endl;
}

int main()
{
  int vertices, edges;
  cin >> vertices >> edges;
  vector<vector<int>> adjList(vertices + 1);
  vector<bool> vis(vertices + 1, false);

  for (int i = 0; i < edges; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= vertices; i++)
  {
    int paths = 0;
    if (!vis[i])
    {
      dfs(i, -1, adjList, vis, i, paths);
      // cout << "Paths: " << paths << endl;
      // printVisitedNodes(vis);
      if (paths == 2)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}