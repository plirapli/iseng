#include <iostream>
#include <string>

using namespace std;

void showArr(int arr[], int size);

void bubbleSort(int arr[], int size);    // Bubble Sort
void insertionSort(int arr[], int size); // Insertion Sort

int main()
{
  int arr[6] = {23, 45, 34, 12, 36, 18};
  int size = 6;

  bubbleSort(arr, size);
  insertionSort(arr, size);

  return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int size)
{
  int temp;

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap el
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  showArr(arr, size);
}

void insertionSort(int arr[], int size)
{
  int i, j, key;
  for (i = 0; i < size - 1; i++)
  {
    key = arr[i];
    j = i - 1;

    /* Bandingkan key sama elemen di kirinya. Kalo lebih kecil,
       tuker sampe key lebih besar dari elemen di kirinya
       atau mentok paling ujung kiri */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = key;
  }
  showArr(arr, size);
}

void showArr(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
    cout << arr[i] << " ";
  cout << "\n";
}