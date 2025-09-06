// https://codeforces.com/problemset/problem/492/A
// Vanya and Cubes

#include <bits/stdc++.h>
using namespace std;

void maxHeightOfPyramid(int cubes)
{
  int usedCubes = 0;
  int height = 0;

  while (height + usedCubes <= cubes)
  {
    cubes -= (height + usedCubes);
    usedCubes += height;
    height++;
  }

  cout << height - 1 << endl;
}

int main()
{
  int cubes;
  cin >> cubes;

  maxHeightOfPyramid(cubes);

  return 0;
}