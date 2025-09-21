// https://codeforces.com/problemset/problem/1097/A
// Gennady and a Card Game
// Codeforces 1097A -> Gennady and a Card Game

#include <bits/stdc++.h>
using namespace std;

void fn(vector<string> cardsInHand, string cardOnTable)
{
  bool canPlay = false;
  char tableCardRank = cardOnTable[0];
  char tableCardSuit = cardOnTable[1];

  for (int i = 0; i < cardsInHand.size(); i++)
  {
    if (cardsInHand[i][0] == tableCardRank || cardsInHand[i][1] == tableCardSuit)
    {
      canPlay = true;
      break;
    }
  }

  if (canPlay)
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
}

int main()
{
  string cardOnTable;
  cin >> cardOnTable;
  vector<string> cardsInHand(5);

  for (int i = 0; i < 5; i++)
  {
    string card;
    cin >> card;
    cardsInHand.push_back(card);
  }

  fn(cardsInHand, cardOnTable);

  return 0;
}