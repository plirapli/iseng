#include <iostream>

using namespace std;

int binarySearch(int arr[], int awal, int akhir, int num);

int main()
{
	int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	int inputNum;

	cout << "Cari nomor: ";
	cin >> inputNum;

	int index = binarySearch(arr, 0, n - 1, inputNum);

	if (index != -1)
		cout << inputNum << " ada di index ke-" << index;
	else
		cout << inputNum << " tidak ditemukan";

	return 0;
}

int binarySearch(int arr[], int awal, int akhir, int num)
{
	if (awal <= akhir)
	{
		int tengah = (awal + akhir) / 2;

		if (num == arr[tengah])
			return tengah;
		else if (num < arr[tengah])
			return binarySearch(arr, awal, tengah - 1, num);
		else
			return binarySearch(arr, tengah + 1, akhir, num);
	}
	return -1;
}