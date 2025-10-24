#include <bits/stdc++.h>
using namespace std;

void fn(int pizza)
{
  int ans = 0;
  while (pizza >= 3)
  {
    int thirdPortion = pizza / 3;
    ans += thirdPortion;
    pizza -= (2 * thirdPortion);
  }

  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  vector<int> nums(t);

  while (t--)
  {
    int pizza;
    cin >> pizza;
    nums.push_back(pizza);
  }

  for (auto it : nums)
    fn(it);

  return 0;
}