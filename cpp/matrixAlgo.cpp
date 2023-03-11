#include <iostream>

using namespace std;

int main()
{
  int A[5][5] =
      {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {1, 2, 3, 4, 5},
      };
  int B[5][5] =
      {
          {1, 0, 0, 0, 0},
          {2, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {4, 0, 0, 0, 0},
          {5, 0, 0, 0, 0},
      };
  int C[5][5];

  // Time complexity = O(n^3)
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      C[i][j] = 0;
      for (int k = 0; k < 5; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
      cout << C[i][j] << " ";
    cout << "\n";
  }

  return 0;
}