#include <iostream>
using namespace std;

int main()
{

	cout << "PROGRAM SKOR KELAYAKAN KARYA CENDEKIA" << endl;
	cout << "======================================" << endl;

	int ipk, lama_studi, asis, tasis, mka, publikasi, tipk, tlama_studi, tpublik, bpublik, total;

	cout << "Input IPK : ";
	cin >> ipk;

	cout << "Input lama studi (dalam semester) : ";
	cin >> lama_studi;

	cout << "Lama menjadi asisten (dalam semester) : ";
	cin >> asis;

	cout << "Banyak MKA : ";
	cin >> mka;

	cout << "Masukkan jenis publikasi ([4] internasional, [3] nasional, [2] regional, [1] UPN) :  ";
	cin >> publikasi;

	cout << "banyak publikasi : ";
	cin >> bpublik;

	if (ipk > 3.5 && lama_studi <= 10 && (asis > 0 || publikasi >= 1))
	{
		if (ipk >= 3.876 && ipk <= 4.00)
			ipk = 20 * 4;
		else if (ipk >= 3.751 && ipk <= 3.875)
			ipk = 20 * 3;
		else if (ipk >= 3.626 && ipk <= 3.750)
			ipk = 20 * 2;
		else
			ipk = 20;

		switch (lama_studi)
		{
		case 10:
			lama_studi = 10 * 1;
			break;
		case 9:
			lama_studi = 10 * 2;
			break;
		case 8:
			lama_studi = 10 * 3;
			break;

		default:
			lama_studi = 10 * 4;
			break;
		}

		switch (asis)
		{
		case 1:
			asis = 10 * 1 * mka;
			break;

		case 2:
			asis = 10 * 2 * mka;
			break;

		case 3:
			asis = 10 * 3 * mka;
			break;

		default:
			asis = 10 * 4 * mka;
			break;
		}

		switch (publikasi)
		{
		case 4:
			publikasi = 10 * 4 * bpublik;
			break;

		case 3:
			publikasi = 10 * 3 * bpublik;
			break;
		case 2:
			publikasi = 10 * 2 * bpublik;
			break;

		default:
			publikasi = 10 * 1 * bpublik;
			break;
		}

		total = ipk + lama_studi + asis + publikasi;
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
