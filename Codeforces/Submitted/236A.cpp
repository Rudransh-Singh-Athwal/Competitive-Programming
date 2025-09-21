// https://codeforces.com/problemset/problem/236/A
// Boy or girl

#include <bits/stdc++.h>
using namespace std;

bool isGirl(string username)
{
  unordered_map<char, bool> mp;
  for (int i = 0; i < username.length(); i++)
  {
    mp[username[i]] = true;
  }

  return !(mp.size() & 1);
}

int main()
{
  string username;
  cin >> username;

  if (isGirl(username))
  {
    cout << "CHAT WITH HER!" << endl;
  }
  else
  {
    cout << "IGNORE HIM!" << endl;
  }

  return 0;
}