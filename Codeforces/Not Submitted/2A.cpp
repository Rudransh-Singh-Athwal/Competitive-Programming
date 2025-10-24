// https://codeforces.com/problemset/problem/2/A
// Winner
// Codeforces 2A -> Winner

#include <bits/stdc++.h>
using namespace std;

void findWinner(unordered_map<string, pair<int, int>> &mp)
{
  int maxi = INT_MIN;
  int winnersTimestamp = INT_MAX;
  string winner = "";
  for (auto it : mp)
  {
    int score = it.second.first;
    int timestamp = it.second.second;
    if (score > maxi)
    {
      maxi = score;
      winnersTimestamp = timestamp;
      winner = it.first;
    }
    else if (score == maxi && timestamp < winnersTimestamp)
    {
      winner = it.first;
    }
  }

  cout << winner << endl;
}

void printMap(unordered_map<string, pair<int, int>> &mp)
{
  for (auto it : mp)
  {
    cout << it.first << " -> " << "{" << it.second.first << ", " << it.second.second << "}\n";
  }
}

int main()
{
  int n;
  cin >> n;
  unordered_map<string, pair<int, int>> mp; // player's name -> {score, timestamp}

  for (int i = 1; i <= n; i++)
  {
    string name;
    int score;
    cin >> name >> score;
    if (mp.count(name))
    {
      mp[name].first += score;
    }
    else
    {
      mp[name].first = score;
    }
    mp[name].second = i;
  }

  // printMap(mp);

  findWinner(mp);

  return 0;
}