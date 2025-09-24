// https://codeforces.com/problemset/problem/580/C
// Kefa and Park

#include <bits/stdc++.h>
using namespace std;

bool isLeaf(int node, int parent, vector<vector<int>> &adjList)
{
  return (adjList[node].size() == 1 && adjList[node][0] == parent);
}

void dfs(int node, int parent, int cats, const int maxCats, vector<bool> &isCatPresent, vector<vector<int>> &adjList, int &pathsCount)
{
  if (cats > maxCats)
  {
    return;
  }
  if (isLeaf(node, parent, adjList) == true)
  {
    if (isCatPresent[node] == true && cats >= maxCats)
      return;
    pathsCount++;
    return;
  }

  for (auto it : adjList[node])
  {
    if (it != parent)
    {
      if (isCatPresent[node] == true)
      {
        dfs(it, node, cats + 1, maxCats, isCatPresent, adjList, pathsCount);
      }
      else
      {
        dfs(it, node, 0, maxCats, isCatPresent, adjList, pathsCount);
      }
    }
  }
  return;
}

int main()
{
  int n, maxCats;
  cin >> n >> maxCats;
  vector<bool> isCatPresent(n + 1, false);
  vector<vector<int>> adjList(n + 1);

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    isCatPresent[i] = x;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int pathsCount = 0;
  dfs(1, -1, 0, maxCats, isCatPresent, adjList, pathsCount);

  cout << pathsCount << endl;

  return 0;
}