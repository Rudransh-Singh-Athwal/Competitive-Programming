// https://codeforces.com/problemset/problem/522/A
// Reposts

#include <bits/stdc++.h>
using namespace std;

void convert_to_lowercase(string &name)
{
  for (int i = 0; i < name.length(); i++)
  {
    if (name[i] >= 'A' && name[i] <= 'Z')
    {
      char low = tolower(name[i]);
      name[i] = low;
    }
  }
}

int dfs(string user, unordered_map<string, vector<string>> &mp)
{
  if (!mp.count(user))
    return 1;

  int ans = 0;

  for (string it : mp[user])
  {
    ans = max(ans, 1 + dfs(it, mp));
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> input;
  unordered_map<string, vector<string>> mp; // from user -> to user
  for (int i = 0; i < n; i++)
  {
    string name1, name2, temp;
    cin >> name1 >> temp >> name2;

    convert_to_lowercase(name1);
    convert_to_lowercase(name2);

    mp[name2].push_back(name1);
  }

  int ans = dfs("polycarp", mp);

  cout << ans << endl;

  return 0;
}