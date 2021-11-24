#include <iostream>
#include <string>

using namespace std;

int *max(int arr[], int size);

int main()
{
  int arr[6] = {23, 45, 34, 12, 36, 18}, temp;

  // Bubble Sort
  for (int i = 0; i < 6; i++)
  {
    for (int j = i + 1; j < 6; j++)
    {
      if (arr[j] < arr[i])
      {
        // Swap el
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for (int i = 0; i < 6; i++)
    cout << arr[i] << " ";

  return 0;
}