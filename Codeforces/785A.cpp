// https://codeforces.com/problemset/problem/785/A
// Anton and Polyhedrons

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int totalFaces = 0;

  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;
    if (input == "Tetrahedron")
      totalFaces += 4;
    else if (input == "Cube")
      totalFaces += 6;
    else if (input == "Octahedron")
      totalFaces += 8;
    else if (input == "Dodecahedron")
      totalFaces += 12;
    else
      totalFaces += 20;
  }

  cout << totalFaces << endl;

  return 0;
}