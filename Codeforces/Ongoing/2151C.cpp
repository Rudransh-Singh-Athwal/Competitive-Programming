// https://codeforces.com/problemset/problem/2151/C
// Incremental Stay
// Codeforces 2151C -> Incremental Stay

#include <bits/stdc++.h>
using namespace std;

long long fn(int n, vector<long long> &nums)
{
  long long ans = 0;
  int i = 0;
  bool sub = true;
  while (i < nums.size())
  {
    int remaining = nums.size() - i;
    if (remaining < n)
    {
      int half = remaining / 2;
      int j = 0;

      // Subtract first half
      for (; j < half; ++j, ++i)
      {
        ans -= nums[i];
      }

      // Add second half
      for (; j < remaining; ++j, ++i)
      {
        ans += nums[i];
      }

      // Done, as all remaining elements are processed
      break;
    }

    for (int j = 0; j < n && i < nums.size(); j++, i++)
    {
      if (sub)
        ans -= nums[i];
      else
        ans += nums[i];
    }
    sub = !sub;
  }

  return ans;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<long long> input;
    for (int i = 0; i < (2 * n); i++)
    {
      long long x;
      cin >> x;
      input.push_back(x);
    }
    sort(input.begin(), input.end());
    for (int i = 1; i <= n; i++)
    {
      cout << fn(i, input) << " ";
    }
    cout << endl;
  }
  return 0;
}