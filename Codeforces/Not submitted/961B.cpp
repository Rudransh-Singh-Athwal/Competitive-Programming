// https://codeforces.com/problemset/problem/961/B
// Lecture Sleep
// Codeforces 961 B -> Lecture Sleep

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> theorems;
  vector<bool> isAwake;
  int theoremsNotedWhileAwake = 0;

  for (int i = 0; i < n; i++)
  {
    int theorem;
    cin >> theorem;
    theorems.push_back(theorem);
  }
  for (int i = 0; i < n; i++)
  {
    int awake;
    cin >> awake;
    isAwake.push_back(awake);
  }

  for (int i = 0; i < n; i++)
  {
    if (isAwake[i])
    {
      theoremsNotedWhileAwake += theorems[i];
    }
  }

  int left = k, right = n - 1;
  int additionalTheorems = 0;
  for (int i = left; i <= right; i++)
  {
    if (!isAwake[i])
    {
      additionalTheorems += theorems[i];
    }
  }

  int maxAdditionalTheorems = additionalTheorems;

  while (left > 0)
  {
    if (!isAwake[right])
    {
      additionalTheorems -= theorems[right];
    }
    if (!isAwake[left - 1])
    {
      additionalTheorems += theorems[left - 1];
    }

    maxAdditionalTheorems = max(maxAdditionalTheorems, additionalTheorems);

    left--;
    right--;
  }
  cout << theoremsNotedWhileAwake + maxAdditionalTheorems << endl;

  return 0;
}