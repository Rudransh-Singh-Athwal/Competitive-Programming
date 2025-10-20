// https://codeforces.com/problemset/problem/1/B
// Spreadsheets

#include <bits/stdc++.h>
using namespace std;

bool isAlphabet(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isNumber(char ch)
{
  return (ch >= '0' && ch <= '9');
}

bool isType_Col_Row(string str)
{
  // The pattern is: letters followed by numbers
  // We've seen at least one letter, then at least one number
  bool foundNumber = false;

  for (int i = 0; i < str.length(); i++)
  {
    if (isNumber(str[i]))
    {
      foundNumber = true;
    }
    else if (foundNumber)
    {
      // Found a letter after a number - this is RxCy format
      return false;
    }
  }

  return foundNumber; // Must have at least one number
}

void convert_CR_to_RxCy(string str, unordered_map<char, int> &mp) // BC23 -> R23C55
{
  int index = 0;
  int row = 0;
  int col = 0;

  while (index < str.length() && isAlphabet(str[index]))
  {
    col = col * 26 + mp[str[index]];
    index++;
  }

  while (index < str.length())
  {
    row *= 10;
    row += (str[index] - '0');
    index++;
  }

  cout << "R" << row << "C" << col << endl;
}

void convert_RxCy_to_CR(string str, unordered_map<char, int> &mp) // R23C55 -> BC23
{
  int index = 1;
  int row = 0;
  int col = 0;
  string convertedCol = "";

  while (index < str.length() && isNumber(str[index]))
  {
    row *= 10;
    row += (str[index] - '0');
    index++;
  }

  index++;

  while (index < str.length())
  {
    col *= 10;
    col += (str[index] - '0');
    index++;
  }

  while (col > 0)
  {
    col--;
    char ch = 'A' + (col % 26);
    convertedCol.push_back(ch);
    col /= 26;
  }

  reverse(convertedCol.begin(), convertedCol.end());

  cout << convertedCol << row << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<string> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  char ch1 = 'A';
  char ch2 = 'a';
  unordered_map<char, int> mp;
  for (int i = 1; i <= 26; i++)
  {
    mp[ch1++] = i;
    mp[ch2++] = i;
  }

  for (auto it : nums)
  {
    if (isType_Col_Row(it))
      convert_CR_to_RxCy(it, mp);
    else
      convert_RxCy_to_CR(it, mp);
  }

  return 0;
}