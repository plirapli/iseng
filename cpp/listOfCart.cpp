#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// Muhammad Rafli / 123210078
	string nama[3];
	int i, harga[3], jml[3], totalHarga[3], totalJml = 0, total = 0, namaMax, jmlStrip;

	for (i = 0; i < 3; i++)
	{
		cout << "Item #" << i + 1 << "\n";
		cout << "Nama" << setw(12) << ": ";
		getline(cin, nama[i]);

		cout << "Jumlah" << setw(10) << ": ";
		cin >> jml[i];

		cout << "Harga satuan" << setw(4) << ": ";
		cin >> harga[i];
		cin.ignore(1, '\n');
		cout << "\n";
	}

	// Menghitung Total
	for (i = 0; i < 3; i++)
	{
		totalHarga[i] = harga[i] * jml[i];
		totalJml += jml[i];
		total += totalHarga[i];
	}

	for (i = 0; i < 3; i++)
	{
		int dataKeN = nama[i].length();

		// Mengecek apakah nilai sebelumnya lebih kecil dari nilai sekarang.
		// Jika iya, nilai sebelumnya = nilai sekarang.
		namaMax = (dataKeN > namaMax ? dataKeN : namaMax);
	}

	// Menghitung jumlah strip
	jmlStrip = 8 + 6 + namaMax - 1 + 11 + 17 + 13;

	cout << "\n"
			 << "Rekap :"
			 << "\n";

	// == Header ==
	cout << setfill('-') << setw(jmlStrip) << "-"
			 << "\n";

	cout << setfill(' ')
			 << "|"
			 << setw(4) << "No" << setw(3) << "|"
			 << setw(6) << "Nama" << setw(namaMax - 1) << "|"
			 << setw(8) << "Jumlah" << setw(3) << "|"
			 << setw(14) << "Harga Satuan" << setw(3) << "|"
			 << setw(7) << "Total" << setw(6) << "|"
			 << "\n";

	cout << setfill('-') << setw(jmlStrip) << "-"
			 << "\n";
	// == End Header ==

	// == Start Row ==
	for (i = 0; i < 3; i++)
	{
		cout << setfill(' ')
				 << "|"
				 << setw(4) << i + 1 << setw(3) << "|"
				 << setw(namaMax + 2) << nama[i] << setw(3) << "|"
				 << setw(8) << jml[i] << setw(3) << "|"
				 << setw(14) << harga[i] << setw(3) << "|"
				 << setw(10) << totalHarga[i] << setw(3) << "|"
				 << "\n";
	}
	// == End Row ==

	cout << setfill('-') << setw(jmlStrip) << "-"
			 << "\n";

	cout << setfill(' ')
			 << "|"
			 << setw(7 + namaMax + 2) << "Total" << setw(3) << "|"
			 << setw(8) << totalJml << setw(3) << "|"
			 << setw(27) << total << setw(3) << "|"
			 << "\n";

	cout << setfill('-') << setw(jmlStrip) << "-";

	return 0;
}