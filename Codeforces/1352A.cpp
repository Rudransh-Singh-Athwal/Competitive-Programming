// https://codeforces.com/problemset/problem/1352/A
// Sum of Round Numbers

#include <bits/stdc++.h>
using namespace std;

void sumOfRoundNumbers(int number)
{
  string num = to_string(number);
  int size = num.length();
  int count = 0;
  vector<int> nums;

  for (int i = 0; i < size; i++)
  {
    string temp = "";
    if (num[i] != '0')
    {
      count++;
      temp += num[i];
      for (int x = i + 1; x < size; x++)
      {
        temp += '0';
      }
      nums.push_back(stoi(temp));
    }
  }

  cout << count << endl;
  for (auto it : nums)
  {
    cout << it << " ";
  }
  cout << endl;

  return;
}

int main()
{
  int n;
  cin >> n;
  vector<int> input;

  for (int i = 0; i < n; i++)
  {
    int inputNumber;
    cin >> inputNumber;
    input.push_back(inputNumber);
  }

  for (auto it : input)
  {
    sumOfRoundNumbers(it);
  }

  return 0;
}