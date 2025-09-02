// https://codeforces.com/problemset/problem/701/A

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findPairs(unordered_map<int, vector<int>> &mp, const vector<int> &cards, int target)
{
  vector<pair<int, int>> res;
  for (auto cardValue : cards)
  {
    if (mp[cardValue].size() == 0)
      continue;

    pair<int, int> p;
    p.first = mp[cardValue].back();
    mp[cardValue].pop_back();

    int complementCardValue = target - cardValue;

    if (mp.find(complementCardValue) == mp.end() || mp[complementCardValue].size() == 0)
      continue;

    p.second = mp[complementCardValue].back();
    mp[complementCardValue].pop_back();

    res.push_back(p);
  }

  return res;
}

void printPairs(vector<pair<int, int>> pairs)
{
  for (auto pair : pairs)
  {
    cout << pair.first << " " << pair.second << endl;
  }
}

int main()
{
  vector<int> cards;
  long long sum = 0;
  unordered_map<int, vector<int>> mp; // cardValue -> indices shifted by +1

  int numberOfCards;
  cin >> numberOfCards;
  for (int i = 0; i < numberOfCards; i++)
  {
    int cardValue;
    cin >> cardValue;
    sum += cardValue;
    cards.push_back(cardValue);
    mp[cardValue].push_back(i + 1); // 1 based indices
  }

  int pairsCount = numberOfCards / 2;

  int target = static_cast<int>(sum / pairsCount);

  vector<pair<int, int>> pairs = findPairs(mp, cards, target);

  printPairs(pairs);

  return 0;
}