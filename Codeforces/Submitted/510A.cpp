// https://codeforces.com/problemset/problem/510/A
// Fox And Snake

#include <bits/stdc++.h>
using namespace std;

void buildSnake(vector<vector<char>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  bool flag = true;

  for (int i = 0; i < n; i += 2)
  {
    for (int j = 0; j < m; j++)
    {
      matrix[i][j] = '#';
    }
  }

  for (int i = 1; i < n; i += 2)
  {
    if (flag)
    {
      matrix[i][m - 1] = '#';
    }
    else
    {
      matrix[i][0] = '#';
    }
    flag = !flag;
  }
}

void printMatrix(vector<vector<char>> matrix)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

int main()
{
  int rows, cols;
  cin >> rows >> cols;
  vector<vector<char>> matrix(rows, vector<char>(cols, '.'));
  buildSnake(matrix);
  printMatrix(matrix);

  return 0;
}