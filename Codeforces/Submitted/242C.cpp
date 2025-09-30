// https://codeforces.com/contest/242/problem/C
// King's Path

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int segments;
  cin >> segments;
  unordered_map<int, unordered_map<int, bool>> allowed;
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

  while (segments--)
  {
    int row, col1, col2;
    cin >> row >> col1 >> col2;
    int c = col1;
    while (c <= col2)
    {
      if (!allowed.count(row) || !allowed[row].count(c))
        allowed[row][c++] = true;
    }
  }

  queue<pair<int, pair<int, int>>> q; // {distance, {row, col}}
  q.push({0, {x2, y2}});

  while (!q.empty())
  {
    int dist = q.front().first;
    int i = q.front().second.first;
    int j = q.front().second.second;
    q.pop();
    allowed[i][j] = false;

    if (i == x1 && j == x2)
    {
      cout << dist << endl;
      return 0;
    }

    for (auto it : dirs)
    {
      int newR = i + it.first;
      int newC = j + it.second;
      if (!allowed.count(newR) || !allowed[newR].count(newC) || allowed[newR][newC] == false)
        continue;

      if (newR == x1 && newC == y1)
      {
        cout << dist + 1 << endl;
        return 0;
      }
      q.push({dist + 1, {newR, newC}});
      allowed[newR][newC] = false;
    }
  }

  cout << -1 << endl;

  return 0;
}