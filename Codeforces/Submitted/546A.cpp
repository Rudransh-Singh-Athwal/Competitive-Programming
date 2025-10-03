// https://codeforces.com/problemset/problem/546/A
// Soldier and Bananas

#include <bits/stdc++.h>
using namespace std;

// a -> first term
// d -> common difference
// n -> number of terms
int sumOfNTermsOfArithmeticProgression(int a, int d, int n)
{
  int sum = ((n) * ((2 * a) + ((n - 1) * d))) / 2;
  return sum;
}

int main()
{
  int costOfFirstBanana, money, numberOfBananas;
  cin >> costOfFirstBanana >> money >> numberOfBananas;

  int totalAmountRequired = sumOfNTermsOfArithmeticProgression(costOfFirstBanana, ((2 * costOfFirstBanana) - costOfFirstBanana), numberOfBananas);

  int borrowMoney = max(0, totalAmountRequired - money);

  cout << borrowMoney << endl;

  return 0;
}