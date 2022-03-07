#include <iostream>

using namespace std;

// [NOMOR 1]
// struct DataPemesan
// {
// 	int kode, telp;
// 	string nama, alamat, email, tglPesan;
// 	DataPerjalanan perjalanan;
// 	DataPenumpang penumpang[10];
// };

// struct DataPerjalanan
// {
// 	int noKa;
// 	string kereta, tgl, berangkat, tiba;
// };

// struct DataPenumpang
// {
// 	int noID;
// 	string nama, kelas, duduk;
// };

// [NOMOR 2]
// int moreThan4(int arr[][5]);
// void tampilData(int arr[][5]);

// [NOMOR 3]
// float S(int n);

int main()
{
	// [NOMOR 1]
	// DataPemesan pesanan[10];

	// [NOMOR 2]
	// int arr[4][5] =
	// 		{{2, 5, 1, 2, 4},
	// 		 {6, 3, 2, 3, 1},
	// 		 {9, 8, 5, 4, 8},
	// 		 {5, 4, 3, 2, 9}};

	// cout << "Data: \n";
	// tampilData(arr);
	// cout << "Ada " << moreThan4(arr) << " nilai yang > 4.";

	// [NOMOR 3]
	// cout << "S(3) = " << S(3);

	return 0;
}

// int moreThan4(int arr[][5]) // [NOMOR 2]
// {
// 	int jml = 0;
//
// 	for (int i = 0; i < 4; i++)
// 		for (int j = 0; j < 5; j++)
// 			jml = arr[i][j] > 4 ? jml + 1 : jml + 0;
//
// 	return jml;
// }

// void tampilData(int arr[][5]) // [NOMOR 2]
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		for (int j = 0; j < 5; j++)
// 			cout << arr[i][j] << " ";
// 		cout << "\n";
// 	}
// }

// float S(int n) // [NOMOR 3]
// {
// 	float x;
// 	float p = 2 * n;
// 	float q = 3 * n + 1;
//
// 	if (n == 1)
// 	{
// 		cout << p << "/" << q << " = ";
// 		return 0.5;
// 	}
// 	else
// 	{
// 		cout << p << "/" << q << " + ";
// 		return p / q + S(n - 1);
// 	}
// }