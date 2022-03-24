#include <iostream>

using namespace std;

// [NOMOR 1]
struct DataPerjalanan
{
	int noKa;
	string namaKereta, tgl, berangkat, tiba;
};

struct DataPenumpang
{
	int noID;
	string nama, kelas, duduk;
};

struct DataPemesan
{
	int kode, telp;
	string nama, alamat, email, tglPesan;
	DataPerjalanan perjalanan;
	DataPenumpang penumpang[10];
};

DataPemesan pesanan[10];

// [NOMOR 2]
int filterData(int arr[][5]);
void tampilData(int arr[][5]);

// [NOMOR 3]
float S(int n);

int main()
{
	// [NOMOR 2]
	int arr[4][5] = {
			{1, 2, 5, 4, 2},
			{2, 6, 3, 1, 3},
			{5, 9, 8, 8, 4},
			{3, 5, 4, 9, 2}};

	cout << "2. Searching \n"
			 << "Data: \n";
	tampilData(arr);
	cout << "Ada " << filterData(arr) << " nilai yang < 5.";

	cout << "\n\n";

	// [NOMOR 3]
	cout << "3. Deret Rekursif \n"
			 << "S(3) = " << S(3);
}

int filterData(int arr[][5]) // [NOMOR 2]
{
	int jml = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			jml = arr[i][j] < 5 ? jml + 1 : jml + 0;

	return jml;
}

void tampilData(int arr[][5]) // [NOMOR 2]
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

float S(int n) // [NOMOR 3]
{
	float p = 2 * n;
	float q = 3 * n + 1;

	cout << p << "/" << q << (n == 1 ? " = " : " + ");
	return (n == 1) ? 0.5 : (p / q + S(n - 1));
}