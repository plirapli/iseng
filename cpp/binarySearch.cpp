#include <iostream>

using namespace std;

void showArr(int arr[], int n);
void bubbleSort(int (&arr)[10]);
int binarySearch(int arr[], int awal, int akhir, int num);

int main()
{
	int arr[] = {3, 7, 29, 1, 15, 18, 40, 36, 33, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	int inputNum;

	showArr(arr, n);
	cout << "(Unsorted) \n";

	bubbleSort(arr); // sorting arr (asc)
	showArr(arr, n);
	cout << "(Sorted) \n\n";

	cout << "Cari nomor: ";
	cin >> inputNum;
	int i = binarySearch(arr, 0, n - 1, inputNum);

	cout << "---------------- \n";

	if (i != -1)
		cout << inputNum << " ada di index ke-" << i;
	else
		cout << inputNum << " tidak ditemukan";

	return 0;
}

void showArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void bubbleSort(int (&arr)[10])
{
	int temp;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				// Swap arr el
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int binarySearch(int arr[], int awal, int akhir, int num)
{
	/* Jika index awal <= index akhir, maka lakukan pencarian,
		 jika tidak maka pencarian tidak ditemukan. */
	if (awal <= akhir)
	{
		int tengah = (awal + akhir) / 2;

		/* - Jika input = nilai tengah, maka fungsi mengembalikan nilai tengah.
			 - Jika input berada di sisi kiri nilai tengah,
				 maka lakukan pemanggilan fungsi lagi (rekursif) dengan nilai tengah-1 sebagai parameter akhir
			 - Jika input berada di sisi kanan nilai tengah,
				 maka lakukan pemanggilan fungsi lagi (rekursif) dengan nilai tengah+1 sebagai parameter awal
		*/
		return (num == arr[tengah])	 ? tengah
					 : (num < arr[tengah]) ? binarySearch(arr, awal, tengah - 1, num)
																 : binarySearch(arr, tengah + 1, akhir, num);
	}
	return -1;
}