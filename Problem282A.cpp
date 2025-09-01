// https://codeforces.com/problemset/problem/282/A

#include <bits/stdc++.h>
using namespace std;

void increment(int &x)
{
  x = x + 1;
}

void decrement(int &x)
{
  x = x - 1;
}

int main()
{
  int x = 0;
  int numberOfStatements;
  // cout << "Enter the number of statements in the program: ";
  cin >> numberOfStatements;
  vector<string> input;
  // cout << "Enter " << numberOfStatements << " input statements\n";
  for (int i = 0; i < numberOfStatements; i++)
  {
    string temp;
    cin >> temp;
    input.push_back(temp);
  }
  for (auto it : input)
  {
    if (it[1] == '+')
      increment(x);
    else
      decrement(x);
  }
  cout << x << endl;

  return 0;
}