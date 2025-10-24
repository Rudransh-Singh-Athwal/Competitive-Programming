// https://codeforces.com/problemset/problem/161/D
// Distance in Tree
// Codeforces 161D -> Distance in Tree

#include <bits/stdc++.h>
using namespace std;

void fn(int root, vector<vector<int>> &adjList, set<pair<int, int>> &st, const int n, const int target)
{
  vector<bool> vis(n + 1, false);
  queue<pair<int, int>> q;
  vis[root] = 1;
  q.push({root, 0});

  while (!q.empty())
  {
    int node = q.front().first;
    int dist = q.front().second;
    // vis[node] = 1;
    q.pop();

    if (dist == target)
    {
      int a = min(root, node), b = max(root, node);
      st.insert({a, b});
      continue;
    }

    if (dist + 1 <= target)
    {
      for (auto it : adjList[node])
      {
        if (!vis[it])
        {
          vis[it] = 1;
          q.push({it, dist + 1});
        }
      }
    }
  }
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<vector<int>> adjList(n + 1);
  set<pair<int, int>> st;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
  {
    fn(i, adjList, st, n, target);
  }

  cout << st.size() << endl;

  return 0;
}