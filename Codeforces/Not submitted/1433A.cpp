// https://codeforces.com/problemset/problem/1433/A
// Boring Apartments

#include <bits/stdc++.h>
using namespace std;

void findPressedDigits(int n)
{
  int digitsPressed = 0;
  int skipRows = (n % 10) - 1;
  digitsPressed = skipRows * 10;
  string str = to_string(n);
  int len = str.length();
  if (len == 1)
  {
    digitsPressed += 1;
  }
  else if (len == 2)
  {
    digitsPressed += 3;
  }
  else if (len == 3)
  {
    digitsPressed += 6;
  }
  else
  {
    digitsPressed += 10;
  }

  cout << digitsPressed << endl;
}

int main()
{
  int n;
  cin >> n;

  vector<int> apartmentsThatAnsweredCall;

  for (int i = 0; i < n; i++)
  {
    int apartmentNumber;
    cin >> apartmentNumber;

    apartmentsThatAnsweredCall.push_back(apartmentNumber);
  }

  for (auto answeredCall : apartmentsThatAnsweredCall)
  {
    findPressedDigits(answeredCall);
  }

  return 0;
}