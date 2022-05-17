#include <iostream>
#include <string>

using namespace std;

void showArr(int arr[], int size);

void bubbleSort(int arr[], int size);    // Bubble Sort
void insertionSort(int arr[], int size); // Insertion Sort
void selectionSort(int arr[], int n);    // Selection Sort
void shellSort(int arr[], int n);        // Shell Sort

void quickSort(int arr[], int start, int end); // Quick Sort
int partition(int arr[], int start, int end);

int main()
{
  int arr[6] = {23, 45, 34, 12, 36, 18};
  int size = 6;

  cout << "Unsorted \t: ";
  showArr(arr, size);
  cout << "\n";

  cout << "Bubble sort \t: ";
  bubbleSort(arr, size);
  showArr(arr, size);

  // cout << "Insertion sort \t: ";
  // insertionSort(arr, size);
  // showArr(arr, size);

  // cout << "Selection sort \t: ";
  // selectionSort(arr, size);
  // showArr(arr, size);

  // cout << "Shell sort \t: ";
  // shellSort(arr, size);
  // showArr(arr, size);

  // cout << "Quick sort \t: ";
  // quickSort(arr, 0, size - 1);
  // showArr(arr, size);

  return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int size)
{
  int i, j, temp;
  int jml[size] = {}, total = 0; // Variabel menghitung jumlah

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      jml[i]++;
      if (arr[j] > arr[j + 1])
      {
        // Swap element
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    // cout << "Perulangan ke-" << i << " = " << jml[i] << "\n";
  }

  // for (i = 0; i < size; i++)
  //   total += jml[i];

  // cout << "Total = " << total << "\n";
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
    while (key < arr[j] && j >= 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n)
{
  int i, j, temp, minIdx;

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

      // Put temp (the original a[i]) in its correct location
      arr[j] = temp;
    }
  }
}

int partition(int arr[], int start, int end)
{

  int pivot = arr[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++)
  {
    if (arr[i] <= pivot)
      count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex)
  {
    while (arr[i] <= pivot)
      i++;

    while (arr[j] > pivot)
      j--;

    if (i < pivotIndex && j > pivotIndex)
      swap(arr[i++], arr[j--]);
  }

  return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

  // base case
  if (start >= end)
    return;

  // partitioning the array
  int p = partition(arr, start, end);

  // Sorting the left part
  quickSort(arr, start, p - 1);

  // Sorting the right part
  quickSort(arr, p + 1, end);
}

void showArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << "\n";
}