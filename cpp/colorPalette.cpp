#include <iostream>
using namespace std;

int fungsiIF(int val);

int main()
{
	int warna, pilihan, a, b, c, d;
	string notasi, sifat;
	string perpaduanWarna[5] =
			{"Analogous", "Complementary", "Split Complementary",
			 "Triad Complementary", "Tetrad Complementary"};

	cout << "------------------------- \n"
			 << "Nama \t : Muhammad Rafli \n"
			 << "NIM \t : 123210078 \n"
			 << "------------------------- \n";

	cout << "Program Menentukkan Notasi, Sifat, dan Perpaduan Warna Harmonis Warna-Warni: \n";
	cout << "[1] Orange \t\t"
			 << "[2] Red-Orange \t\t"
			 << "[3] Red \n"

			 << "[4] Red-Violet \t\t"
			 << "[5] Violet \t\t"
			 << "[6] Blue-Violet \n"

			 << "[7] Blue \t\t"
			 << "[8] Blue-Green \t\t"
			 << "[9] Green \n"

			 << "[10] Yellow-Green \t"
			 << "[11] Yellow \t\t"
			 << "[12] Yellow-Orange \n";
	cout << "Kode Warna: ";
	cin >> warna;

	cout << "\n";

	if (warna == 1 || warna == 5 || warna == 9)
		notasi = "Sekunder";
	else if (warna == 11 || warna == 3 || warna == 7)
		notasi = "Primer";
	else
		notasi = "Tersier";

	sifat = (warna >= 1 && warna <= 6) ? "Hangat" : "Sejuk";

	if (warna <= 12)
	{
		cout << "Notasi Warna \t : " << notasi << endl;
		cout << "Sifat Warna \t : " << sifat << endl;
		cout << "Perpaduan Warna Harmonis: \n";
		for (int i = 0; i < 5; i++)
			cout << "[" << i + 1 << "] "
					 << "Perpaduan Warna " << perpaduanWarna[i] << "\n";
		cout << "Pilihan : ";
		cin >> pilihan;
		cout << "Perpaduan Warna " << perpaduanWarna[pilihan] << " dengan warna nomor: ";

		switch (pilihan)
		{
		case 1:
			a = fungsiIF(warna + 1);
			b = fungsiIF(warna - 1);
			c = fungsiIF(warna + 2);
			d = fungsiIF(warna - 2);
			cout << a << ", " << c << " atau " << b << ", " << d << " atau " << a << ", " << b;
			break;

		case 2:
			a = fungsiIF(warna + 6);
			cout << a << endl;
			break;

		case 3:
			a = fungsiIF(warna + 5);
			b = fungsiIF(a + 2);
			cout << a << "," << b << endl;
			break;

		case 4:
			a = fungsiIF(warna + 4);
			b = fungsiIF(a + 4);
			cout << a << "," << b << endl;
			break;

		case 5:
			a = fungsiIF(warna + 3);
			b = fungsiIF(a + 3);
			c = fungsiIF(b + 3);
			cout << a << "," << b << "," << c << endl;
			break;

		default:
			cout << "nomor yang anda pilih tidak tersedia \n";
			break;
		}
	}
	else
		cout << "nomor yang anda pilih tidak tersedia \n";

	return 0;
}

int fungsiIF(int val)
{
	if (val <= 0)
		return val += 12;
	else if (val > 12)
		return val -= 12;
	else
		return val;
}