#include <iostream>
#include <string>

using namespace std;

void showArr(int arr[], int size);

void bubbleSort(int arr[], int size);    // Bubble Sort
void insertionSort(int arr[], int size); // Insertion Sort
void selectionSort(int arr[], int n);    // Selection Sort
void shellSort(int arr[], int n);        // Shell Sort

int main()
{
  int arr[6] = {23, 45, 34, 12, 36, 18};
  int size = 6;

  cout << "Unsorted \t: ";
  showArr(arr, size);
  cout << "Bubble sort \t: ";
  bubbleSort(arr, size);
  // cout << "Insertion sort \t: ";
  // insertionSort(arr, size);
  // cout << "Selection sort \t: ";
  // selectionSort(arr, size);
  // cout << "Shell sort \t: ";
  // shellSort(arr, size);

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
  showArr(arr, size); // Menampilkan array
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
  showArr(arr, size); // Menampilkan array
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
  showArr(arr, n); // Menampilkan array
}

void shellSort(int arr[], int n)
{
  // Start with a big gap, then reduce the gap
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    // Do a gapped insertion sort for this gap size.
    // The first gap elements a[0..gap-1] are already in gapped order
    // keep adding one more element until the entire array is
    // gap sorted
    for (int i = gap; i < n; i++)
    {
      // tampung data kanan ke temp
      int temp = arr[i];

      // shift earlier gap-sorted elements up until the correct
      // location for a[i] is found
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];

      //  put temp (the original a[i]) in its correct location
      arr[j] = temp;
    }
  }
  showArr(arr, n); // Menampilkan array
}

void showArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << "\n";
}