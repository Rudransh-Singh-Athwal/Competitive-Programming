// https://codeforces.com/problemset/problem/161/D
// Distance in Tree
// Codeforces 161D -> Distance in Tree

#include <bits/stdc++.h>
using namespace std;

void fn(int root, vector<vector<int>> &adjList, long long &count, vector<int> &vis, int timer, const int n, const int target)
{
  queue<pair<int, int>> q;
  vis[root] = timer;
  q.push({root, 0});

  while (!q.empty())
  {
    int node = q.front().first;
    int dist = q.front().second;
    q.pop();

    if (dist == target)
    {
      if (root <= node)
        count++;
      continue;
    }

    if (dist + 1 <= target)
    {
      for (auto it : adjList[node])
      {
        if (vis[it] != timer)
        {
          vis[it] = timer;
          q.push({it, dist + 1});
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, target;
  cin >> n >> target;
  vector<vector<int>> adjList(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  vector<int> vis(n + 1, 0);
  int timer = 0;
  long long count = 0;

  for (int i = 1; i <= n; i++)
  {
    timer++;
    fn(i, adjList, count, vis, timer, n, target);
  }

  cout << count << "\n";

  return 0;
}