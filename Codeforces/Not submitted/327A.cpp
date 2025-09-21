// https://codeforces.com/problemset/problem/327/A
// Flipping Game
// Codeforces 327A -> Flipping Game

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  vector<int> input;
  int initialCountOf1s = 0;
  int maxConsecutiveZeroesToBeFlipped = 0;
  int currentZeroes = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    input.push_back(x);
  }

  for (auto el : input)
  {
    if (el == 1)
    {
      initialCountOf1s++;
      currentZeroes--;
    }
    else
    {
      currentZeroes++;
    }
    if (currentZeroes < 0)
      currentZeroes = 0;
    maxConsecutiveZeroesToBeFlipped = max(maxConsecutiveZeroesToBeFlipped, currentZeroes);
  }

  cout << initialCountOf1s + maxConsecutiveZeroesToBeFlipped << endl;

  return 0;
}