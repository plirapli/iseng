#include <iostream>

using namespace std;

void naikkanNilai(int *x, int *y);
const char *namaHari(int n);

int main()
{
	// Pointer Array
	cout << "Pointer Array \n";

	int tgl[] = {27, 8, 1977};
	int *ptgl;
	ptgl = tgl;

	cout << "Nilai yang ditunjuk ptgl = " << *(ptgl + 1) << "\n"
			 << "Alamat dari tgl = " << ptgl;
	cout << "\n\n";

	// Swap Pointer Char
	cout << "Pointer Char \n";

	const char *pnama1 = "hanif";
	const char *pnama2 = "fatimah";
	const char *pnama3 = "zahira";
	const char *pnamaTemp;

	cout << "Before: \n";
	cout << "nama1 = " << pnama1 << "\n"
			 << "nama2 = " << pnama2 << "\n"
			 << "nama3 = " << pnama3;
	cout << "\n\n";

	pnamaTemp = pnama1;
	pnama1 = pnama3;
	pnama3 = pnama2;
	pnama2 = pnamaTemp;

	cout << "After: \n";
	cout << "nama1 = " << pnama1 << "\n"
			 << "nama2 = " << pnama2 << "\n"
			 << "nama3 = " << pnama3;
	cout << "\n\n";

	// Pointer of pointer
	cout << "Pointer of Pointer \n";

	int varX = 273;
	int *ptr1 = &varX;
	int **prt2 = &ptr1;

	cout << "Nilai var X = " << *ptr1 << " (via ptr1) \n"
			 << "Nilai var X = " << **prt2 << " (via ptr2)";
	cout << "\n\n";

	// Pointer as func param
	cout << "Pointer sebagai paramter fungsi \n";

	int a = 3, b = 7;

	cout << "a: " << a << ", b: " << b << " (Before) \n";

	naikkanNilai(&a, &b);
	cout << "a: " << a << ", b: " << b << " (After)";
	cout << "\n\n";

	// Pointer as return val
	cout << "Pointer sebagai nilai return fungsi \n";

	int hari;

	cout << "Hari (1 - 7) > ";
	cin >> hari;

	cout << "Nama hari: " << namaHari(hari);
	cout << "\n\n";

	return 0;
}

void naikkanNilai(int *x, int *y)
{
	*x += 2;
	*y += 2;
}

const char *namaHari(int n)
{
	const char *phari[8] = {
			"err",
			"Senin",
			"Selasa",
			"Rabu",
			"Kamis",
			"Jumat",
			"Sabtu",
			"Minggu",
	};

	return (n < 1 || n > 7) ? phari[0] : phari[n];
}