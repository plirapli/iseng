#include <iostream>

using namespace std;

int main()
{
	int inputJenisBangun, inputNamaBangun;

	cout << "=========================\n"
			 << "Nama \t"
			 << ": Muhammad Rafli \n"
			 << "NIM \t"
			 << ": 123210078 \n"
			 << "=========================\n"
			 << "\n";

	cout << "[1] Bangun datar \n"
			 << "[2] Bangun ruang \n"
			 << "Pilih: ";
	cin >> inputJenisBangun;

	cout << "\n";

	if (inputJenisBangun == 1)
	{
		cout << "Menghitung luas Bangun Datar: \n"
				 << "1. Persegi Panjang \n"
				 << "2. Lingkaran \n"
				 << "3. Jajar genjang \n"
				 << "4. Belah ketupat \n"
				 << "Pilihan: ";
		cin >> inputNamaBangun;

		cout << "\n";

		switch (inputNamaBangun)
		{
			float luas;

		case 1:
		{
			float p, l;

			cout << "Menghitung Luas Persegi Panjang \n";
			cout << "Masukkan Panjang: ";
			cin >> p;
			cout << "Menghitung Lebar: ";
			cin >> l;

			luas = p * l;

			cout << "Luas Persegi Panjang: " << luas;
			break;
		}

		case 2:
		{
			const float pi = 3.14;
			float r;

			cout << "Menghitung Luas Lingkaran \n";
			cout << "Masukkan Jari-jari Lingkaran: ";
			cin >> r;

			luas = pi * r * r;

			cout << "Luas Lingkaran: " << luas;
			break;
		}

		case 3:
		{
			float a, t;

			cout << "Menghitung Luas Jajar Genjang \n";
			cout << "Masukkan Alas: ";
			cin >> a;
			cout << "Menghitung Tinggi: ";
			cin >> t;

			luas = a * t;

			cout << "Luas Jajar Genjang: " << luas;
			break;
		}

		case 4:
		{
			float d1, d2;

			cout << "Menghitung Luas Belah Ketupat \n";
			cout << "Masukkan Diagnoal 1: ";
			cin >> d1;
			cout << "Menghitung Diagonal 2: ";
			cin >> d2;

			luas = 0.5 * d1 * d2;

			cout << "Luas Belah Ketupat: " << luas;
			break;
		}

		default:
			cout << "Pilihan tidak valid";
			break;
		}
	}
	else if (inputJenisBangun == 2)
	{
		cout << "Menghitung Volume Bangun Ruang: \n"
				 << "1. Kubus \n"
				 << "2. Bola \n"
				 << "3. Prisma Segitiga \n"
				 << "Pilihan: ";
		cin >> inputNamaBangun;

		cout << "\n";

		switch (inputNamaBangun)
		{
			float volume;

		case 1:
		{
			float s;

			cout << "Menghitung Volume Kubus \n";
			cout << "Masukkan Besar Sisi Kubus: ";
			cin >> s;

			volume = s * s * s;

			cout << "Volume Kubus: " << volume;
			break;
		}

		case 2:
		{
			const float pi = 3.14;
			const float konstan = 4 / 3;
			float r;

			cout << "Menghitung Volume Bola \n";
			cout << "Masukkan Besar Jari-jari Bola: ";
			cin >> r;

			volume = konstan * pi * r * r * r;

			cout << "Volume Bola: " << volume;
			break;
		}

		case 3:
		{
			float a, t, tPrisma;

			cout << "Menghitung Volume Prisma Segitiga \n";
			cout << "Masukkan Besar Alas Segitiga: ";
			cin >> a;
			cout << "Masukkan Besar Tinggi Segitiga: ";
			cin >> t;

			volume = 0.5 * a * t * tPrisma;

			cout << "Volume Prisma Segitiga: " << volume;
			break;
		}

		default:
			cout << "Pilihan anda tidak valid!";
			break;
		}
	}
	else
		cout << "Input anda tidak valid!";

	return 0;
}