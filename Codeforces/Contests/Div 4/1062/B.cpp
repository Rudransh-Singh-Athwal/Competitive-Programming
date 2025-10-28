#include <bits/stdc++.h>
using namespace std;

bool fn(vector<string> &nums)
{
  string a = nums[0], b = nums[1];
  vector<int> countA(26, 0);
  vector<int> countB(26, 0);

  for (auto ch : a)
  {
    countA[ch - 'a']++;
  }
  for (auto ch : b)
  {
    countB[ch - 'a']++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (countA[i] != countB[i])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<string>> nums(n, vector<string>(2));

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cin >> nums[i][0] >> nums[i][1];
  }

  for (auto it : nums)
  {
    if (fn(it))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}