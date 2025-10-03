// https://codeforces.com/problemset/problem/2151/C
// Incremental Stay
// Codeforces 2151C -> Incremental Stay

#include <bits/stdc++.h>
using namespace std;

void fn(int n, vector<int> &nums)
{
  stack<int> st;
  int ans = 0;
  bool flag = true;
  for (int i = 1; i <= n; i++)
  {
    if (flag)
    {
      st.push(nums[i - 1]);
      if (st.size() == i)
        flag = false;
    }
    else
    {
      int x = nums[i - 1];
      int t = st.top();
      st.pop();
      ans += x - t;
    }
  }

  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < (2 * n); i++)
    {
      int x;
      cin >> x;
      input.push_back(x);
    }
    sort(input.begin(), input.end());
    fn(n, input);
  }
  return 0;
}