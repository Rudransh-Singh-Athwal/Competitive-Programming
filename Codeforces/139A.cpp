// https://codeforces.com/contest/139/problem/A
// Petr and Book
// Codeforces 139A -> Petr and Book

#include <bits/stdc++.h>
using namespace std;

void findDay(int pages, vector<int> pagesPerDay)
{
  for (int i = 1; i <= 7; i++)
  {
    pages -= pagesPerDay[i];
    if (pages <= 0)
    {
      cout << i << endl;
      break;
    }
    if (pages > 0 && i == 7)
    {
      i = 0;
    }
  }
}

int main()
{
  int pages;
  cin >> pages;

  vector<int> pagesPerDay(8, 0);

  for (int i = 1; i <= 7; i++)
  {
    int p;
    cin >> p;
    pagesPerDay[i] = p;
  }

  findDay(pages, pagesPerDay);

  return 0;
}