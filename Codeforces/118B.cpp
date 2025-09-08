// https://codeforces.com/problemset/problem/118/B
// Present from Lena

#include <bits/stdc++.h>
using namespace std;

void printUpperTriangle(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      cout << "  ";
    }

    for (int j = 0; j <= i; j++)
    {
      cout << j;
      if (j < i)
        cout << " ";
    }

    for (int j = i - 1; j >= 0; j--)
    {
      cout << " " << j;
    }
    cout << endl;
  }
}

void printLowerTriangle(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "  ";
    }

    for (int j = 0; j <= n - i; j++)
    {
      cout << j;
      if (j < n - i)
        cout << " ";
    }

    for (int j = n - i - 1; j >= 0; j--)
    {
      cout << " " << j;
    }

    cout << endl;
  }
}

void presentFromLena(int n)
{
  printUpperTriangle(n);
  printLowerTriangle(n);
}

int main()
{
  int n;
  cin >> n;

  presentFromLena(n);

  return 0;
}