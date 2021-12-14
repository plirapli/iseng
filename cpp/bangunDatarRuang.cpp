#include <iostream>

using namespace std;

int main()
{
	int inputJenisBangun, inputNamaBangun;
	string bangun[2][4] =
			{{"Persegi Panjang", "Lingkaran", "Jajar Genjang", "Belah Ketupat"},
			 {"Kubus", "Bola", "Prisma Segitiga"}};

	cout << "=========================\n"
			 << "Nama \t : Muhammad Rafli \n"
			 << "NIM \t : 123210078 \n"
			 << "=========================\n\n";

	cout << "[1] Bangun datar \n"
			 << "[2] Bangun ruang \n"
			 << "Pilih: ";
	cin >> inputJenisBangun;

	cout << "\n";

	if (inputJenisBangun == 1)
	{
		float luas;
		cout << "Menghitung luas Bangun Datar: \n";

		for (int i = 0; i < 4; i++)
			cout << i + 1 << ". " << bangun[0][i] << "\n";

		cout << "Pilihan: ";
		cin >> inputNamaBangun;

		cout << "\n";

		switch (inputNamaBangun)
		{
		case 1:
		{
			float p, l;

			cout << "Menghitung Luas Persegi Panjang \n";
			cout << "Masukkan Panjang: ";
			cin >> p;
			cout << "Menghitung Lebar: ";
			cin >> l;

			luas = p * l;
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
			break;
		}

		default:
			cout << "Pilihan tidak valid";
			break;
		}

		if (luas)
			cout << "Luas " << bangun[0][inputNamaBangun - 1] << ": " << luas;
		else
			cout << "Luas Invalid";
	}
	else if (inputJenisBangun == 2)
	{
		float volume;

		cout << "Menghitung Volume Bangun Ruang: \n";

		for (int i = 0; i < 3; i++)
			cout << i + 1 << ". " << bangun[1][i] << "\n";

		cout << "Pilihan: ";
		cin >> inputNamaBangun;

		cout << "\n";

		switch (inputNamaBangun)
		{
		case 1:
		{
			float s;

			cout << "Menghitung Volume Kubus \n";
			cout << "Masukkan Besar Sisi Kubus: ";
			cin >> s;

			volume = s * s * s;
			break;
		}

		case 2:
		{
			const float pi = 3.14;
			const float konstan = 4.0 / 3.0;
			float r;

			cout << "Menghitung Volume Bola \n";
			cout << "Masukkan Besar Jari-jari Bola: ";
			cin >> r;

			volume = konstan * pi * r * r * r;
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
			cout << "Masukkan Besar Tinggi Prisma: ";
			cin >> tPrisma;

			volume = 0.5 * a * t * tPrisma;
			break;
		}

		default:
			cout << "Pilihan anda tidak valid!";
			break;
		}

		if (volume)
			cout << "Volume " << bangun[1][inputNamaBangun - 1] << ": " << volume;
		else
			cout << "Volume Invalid";
	}
	else
		cout << "Input anda tidak valid!";

	return 0;
}