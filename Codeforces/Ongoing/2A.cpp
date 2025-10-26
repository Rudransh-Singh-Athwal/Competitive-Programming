// https://codeforces.com/problemset/problem/2/A
// Winner
// Codeforces 2A -> Winner

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_map<string, int> mp; // player's name -> score
  vector<pair<string, int>> events;
  int maxScore = INT_MIN;

  for (int i = 1; i <= n; i++)
  {
    string name;
    int score;
    cin >> name >> score;
    events.push_back({name, score});

    if (mp.count(name))
    {
      mp[name] += score;
    }
    else
    {
      mp[name] = score;
    }
    maxScore = max(maxScore, mp[name]);
  }

  // replay events and find who first reaches >= maxScore
  unordered_map<string, int> running;
  for (auto &ev : events)
  {
    running[ev.first] += ev.second;
    if (running[ev.first] >= maxScore)
    {
      cout << ev.first << '\n';
      break;
    }
  }

  return 0;
}