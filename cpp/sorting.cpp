#include <iostream>
#include <string>

using namespace std;

void showArr(int arr[], int size);

void bubbleSort(int arr[], int size);    // Bubble Sort
void insertionSort(int arr[], int size); // Insertion Sort
void selectionSort(int arr[], int n);    // Selection Sort

int main()
{
  int arr[6] = {23, 45, 34, 12, 36, 18};
  int size = 6;

  bubbleSort(arr, size);
  insertionSort(arr, size);
  selectionSort(arr, size);

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
        // Swap element
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

    /* Bandingkan key sama elemen di kirinya. Kalo key lebih kecil,
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

void selectionSort(int arr[], int n)
{
  int i, j, minIdx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++)
  {
    // Cari elemen terkecil mulai dari elemen ke-i
    minIdx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[minIdx])
        minIdx = j;

    // Tukar elemen terkecil dengan elemen ke-i
    int temp = arr[minIdx];
    arr[minIdx] = arr[i];
    arr[i] = temp;
  }
  showArr(arr, n);
}

void showArr(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
    cout << arr[i] << " ";
  cout << "\n";
}