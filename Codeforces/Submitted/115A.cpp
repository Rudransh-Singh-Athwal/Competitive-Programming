// https://codeforces.com/problemset/problem/115/A
// Party

#include <bits/stdc++.h>
using namespace std;

int findMinGroups(queue<int> &q, vector<int> &senior)
{
  int ans = 1;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    int depth = 1;
    while (senior[node] != -1)
    {
      node = senior[node];
      depth++;
    }
    ans = max(ans, depth);
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> inDeg(n + 1, 0);
  vector<int> senior(n + 1, -1);
  queue<int> q;

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    senior[i] = x;
    if (x != -1)
      inDeg[x]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (inDeg[i] == 0)
    {
      q.push(i);
    }
  }

  int minGroups = findMinGroups(q, senior);
  cout << minGroups << endl;

  return 0;
}