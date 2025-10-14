// https://codeforces.com/problemset/problem/1324/D
// Pair of Topics

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  vector<int> C(n);
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> B[i];
  }

  for (int i = 0; i < n; i++)
  {
    C[i] = A[i] - B[i];
  }
  sort(C.begin(), C.end());

  int left = 0, right = n - 1;
  while (left < right)
  {
    if (C[left] + C[right] > 0)
    {
      ans += (right - left);
      right--;
    }
    else
      left++;
  }

  cout << ans << endl;

  return 0;
}