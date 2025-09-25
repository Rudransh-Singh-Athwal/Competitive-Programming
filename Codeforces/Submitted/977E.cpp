// https://codeforces.com/problemset/problem/977/E
// Cyclic Components

#include <bits/stdc++.h>
using namespace std;

void markAllAdjacentsVisited(int start_node, vector<bool> &vis, const vector<vector<int>> &adjList)
{
  queue<int> q;
  q.push(start_node);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    vis[node] = true;
    for (auto it : adjList[node])
    {
      if (!vis[it])
        q.push(it);
    }
  }
}

bool dfs(int curr_node, int parent, const vector<vector<int>> &adjList, vector<bool> &vis, const int start_node, bool firstNode)
{
  vis[curr_node] = true;
  if (adjList[curr_node].size() != 2)
  {
    markAllAdjacentsVisited(start_node, vis, adjList);
    return false;
  }
  if (parent != -1 && curr_node == start_node)
  {
    return true;
  }

  if (parent == -1)
  {
    return dfs(adjList[curr_node][0], curr_node, adjList, vis, start_node, false);
  }
  else
  {
    if (adjList[curr_node][0] == parent)
    {
      return dfs(adjList[curr_node][1], curr_node, adjList, vis, start_node, false);
    }
    else
    {
      return dfs(adjList[curr_node][0], curr_node, adjList, vis, start_node, false);
    }
  }
}

void printVisited(vector<bool> &vis)
{
  cout << "Visited nodes\n";
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

  if (vertices < 3 || edges < 3)
  {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 1; i <= vertices; i++)
  {
    if (!vis[i])
    {
      bool isCycle = dfs(i, -1, adjList, vis, i, true);
      // printVisited(vis);
      if (isCycle)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}