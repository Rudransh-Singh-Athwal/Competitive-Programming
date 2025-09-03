// https://codeforces.com/problemset/problem/723/A
// The New Year: Meeting Friends

#include <bits/stdc++.h>
using namespace std;

void findMeetingPoint(int a, int b, int c)
{
  int meetAtA = abs(a - b) + abs(a - c);
  int meetAtB = abs(a - b) + abs(b - c);
  int meetAtC = abs(a - c) + abs(b - c);

  int ans = min(meetAtA, min(meetAtB, meetAtC));
  cout << ans << endl;

  return;
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  findMeetingPoint(a, b, c);

  return 0;
}