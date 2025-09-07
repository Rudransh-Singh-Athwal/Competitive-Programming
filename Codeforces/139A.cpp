// https://codeforces.com/contest/139/problem/A
// Petr and Book

#include <bits/stdc++.h>
using namespace std;

void findDay(int pages, vector<int> dayWisePagesRead)
{
  int totalPagesInAWeek = 0;
  for (auto it : dayWisePagesRead)
  {
    totalPagesInAWeek += it;
  }

  pages %= totalPagesInAWeek;
  if (pages == 0)
    pages = totalPagesInAWeek;

  for (int i = 1; i <= 7; i++)
  {
    pages -= dayWisePagesRead[i];
    if (pages <= 0)
    {
      cout << i << endl;
      break;
    }
  }
}

int main()
{
  int pages;
  cin >> pages;

  vector<int> dayWisePagesRead(8, 0);

  for (int i = 1; i <= 7; i++)
  {
    int p;
    cin >> p;
    dayWisePagesRead[i] = p;
  }

  findDay(pages, dayWisePagesRead);

  return 0;
}