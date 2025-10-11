// https://codeforces.com/problemset/problem/313/B
// Ilya and Queries

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n;
  vector<vector<int>> queries;
  cin >> s >> n;

  vector<int> dp(s.length() + 1);
  dp[1] = 0;

  for (int i = 2; i <= s.length(); i++)
  {
    dp[i] = dp[i - 1] + (s[i - 1] == s[i - 2]);
  }

  for (int i = 0; i < n; i++)
  {
    vector<int> query;
    int l, r;
    cin >> l >> r;
    query.push_back(l);
    query.push_back(r);

    queries.push_back(query);
  }

  for (int i = 0; i < queries.size(); i++)
  {
    int l = queries[i][0];
    int r = queries[i][1];
    cout << dp[r] - dp[l] << endl;
  }

  return 0;
}