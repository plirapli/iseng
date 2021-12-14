#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	float ipk;
	int lamaStudi, lamaAsisten, jmlMKA, jmlPublikasi, publikasi, total;

	cout << "Indeks Prestasi Kumulatif"
			 << "\t"
			 << ": ";
	cin >> ipk;

	cout << "Lama Studi (semester)"
			 << "\t\t"
			 << ": ";
	cin >> lamaStudi;

	cout << "Lama menjadi Asisten (semester)"
			 << "\t"
			 << ": ";
	cin >> lamaAsisten;

	cout << "Banyaknya MKA Praktikum"
			 << "\t\t"
			 << ": ";
	cin >> jmlMKA;

	cout << "[4] Internasional"
			 << "\n"
			 << "[3] Nasional"
			 << "\n"
			 << "[2] Regional"
			 << "\n"
			 << "[1] UPN"
			 << "\n"
			 << "[0] Tidak Pernah"
			 << "\n"
			 << "Jenis tingkat publikasi"
			 << "\t"
			 << ": ";
	cin >> publikasi;

	if (publikasi >= 1)
	{
		cout << "Banyaknya publikasi"
				 << "\t\t"
				 << ": ";
		cin >> jmlPublikasi;
	}

	if (ipk > 3.5 && lamaStudi <= 10 && (lamaAsisten > 0 || publikasi >= 1))
	{
		if (ipk >= 3.876 && ipk <= 4.00)
			ipk = 20 * 4;
		else if (ipk >= 3.751 && ipk <= 3.875)
			ipk = 20 * 3;
		else if (ipk >= 3.626 && ipk <= 3.750)
			ipk = 20 * 2;
		else
			ipk = 20;

		switch (lamaStudi)
		{
		case 10:
			lamaStudi = 10 * 1;
			break;
		case 9:
			lamaStudi = 10 * 2;
			break;
		case 8:
			lamaStudi = 10 * 3;
			break;

		default:
			lamaStudi = 10 * 4;
			break;
		}

		switch (lamaAsisten)
		{
		case 1:
			lamaAsisten = 10 * 1 * jmlMKA;
			break;

		case 2:
			lamaAsisten = 10 * 2 * jmlMKA;
			break;

		case 3:
			lamaAsisten = 10 * 3 * jmlMKA;
			break;

		default:
			lamaAsisten = 10 * 4 * jmlMKA;
			break;
		}

		switch (publikasi)
		{
		case 4:
			publikasi = 10 * 4 * jmlPublikasi;
			break;

		case 3:
			publikasi = 10 * 3 * jmlPublikasi;
			break;
		case 2:
			publikasi = 10 * 2 * jmlPublikasi;
			break;

		default:
			publikasi = 10 * 1 * jmlPublikasi;
			break;
		}

		total = ipk + lamaStudi + lamaAsisten + publikasi;
		cout << "\n"
				 << "Mahasiswa tersebut berhak mendapat Karya Cendikia."
				 << "\n"
				 << "Jumlah Skor"
				 << "\t"
				 << ": " << total;
	}
	else
		cout << "\n"
				 << "Mohon maaf anda tidak berhak mendapat Karya Cendikia.";

	return 0;
}