// https://codeforces.com/problemset/problem/281/A
// Word Capitalization

#include <bits/stdc++.h>
using namespace std;

void capitalize(string &word)
{
  int n = word.length();
  if (word[0] >= 'A' && word[0] <= 'Z')
  {
    return;
  }
  char ch = word[0] - 32;
  word[0] = ch;
}

int main()
{
  string word;
  cin >> word;
  capitalize(word);
  cout << word << endl;

  return 0;
}