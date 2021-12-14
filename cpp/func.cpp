#include <iostream>

using namespace std;

void volumeKubus();
void luasKubus(int s);
void volumeBalok(int *outVolume);
void luasBalok(int &outLuas);
float volumeTabung(int r, int t);

int main()
{
	char menu;

	do
	{
		system("CLS");
		cout << "TUGAS PROCEDURE/FUNCTION \n"
				 << "Nama \t: Muhammad Rafli \n"
				 << "NIM \t: 123210078 \n"
				 << "Kelas \t: IF-C \n";
		cout << "------------------------------------------------------------------ \n";

		cout << "Menu : \n"
				 << "1. Luas Lingkaran (tanpa fungsi) \n"
				 << "2. Volume Kubus (fungsi void tanpa parameter) \n"
				 << "3. Luas Kubus (fungsi void dengan parameter masukan) \n"
				 << "4. Volume Balok (fungsi void dengan parameter keluaran - address) \n"
				 << "5. Luas Balok (fungsi void dengan parameter keluaran - ref) \n"
				 << "6. Volume Tabung (fungsi void tanpa parameter) \n"
				 << "Pilih no = ";
		cin >> menu;

		cout << "------------------------------------------------------------------ \n";

		switch (menu)
		{
		case '1':
		{
			int r;
			cout << "Rumus Luas Lingkaran = 3.14 * r * r \n";
			cout << "Input jari-jari (r) = ";
			cin >> r;

			cout << "Luas Lingkaran = " << 3.14 * r * r;
			break;
		}

		case '2':
			volumeKubus();
			break;

		case '3':
		{
			int s;
			cout << "Rumus Luas Kubus = 6 * s * s \n";
			cout << "Input sisi (s) = ";
			cin >> s;
			luasKubus(s);
			break;
		}

		case '4':
		{
			int volume;
			volumeBalok(&volume);
			cout << "Volume Balok = " << volume;
			break;
		}

		case '5':
		{
			int luas;
			luasBalok(luas);
			cout << "Luas Balok = " << luas;
			break;
		}

		case '6':
		{
			int r, t;
			cout << "Rumus Volume Tabung = 3.14 * r * r * t \n";
			cout << "Input jari-jari (r) = ";
			cin >> r;
			cout << "Input tinggi (t) = ";
			cin >> t;

			cout << "Volume Tabung = " << volumeTabung(r, t);
			break;
		}

		default:
			cout << "Tidak ada di pilihan menu. \n";
			break;
		}
		cout << "\n"
				 << "------------------------------------------------------------------ \n";

		do
		{
			cout << "Mau ulangi lagi (Y/N)? ";
			cin >> menu;

			if (menu != 'y' && menu != 'n')
				cout << "Pilihan tidak valid! \n";

		} while (menu != 'y' && menu != 'n');

	} while (menu == 'y' || menu == 'Y');

	cout << "Terima kasih.";

	return 0;
}

void volumeKubus()
{
	int s;
	cout << "Rumus Volume Kubus = s * s * s \n";
	cout << "Input sisi (s) = ";
	cin >> s;
	cout << "Luas Kubus = " << s * s * s;
}

void luasKubus(int s)
{
	cout << "Luas Kubus = " << 6 * s * s;
}

void volumeBalok(int *outVolume)
{
	int p, l, t;
	cout << "Rumus Volume Balok = p * l * t \n";
	cout << "Input panjang (p) = ";
	cin >> p;
	cout << "Input lebar (l) = ";
	cin >> l;
	cout << "Input tinggi (t) = ";
	cin >> t;

	*outVolume = p * l * t;
}

void luasBalok(int &outLuas)
{
	int p, l, t;
	cout << "Rumus Luas Balok = 2 * (p * l + p * t + l * t) \n";
	cout << "Input panjang (p) = ";
	cin >> p;
	cout << "Input lebar (l) = ";
	cin >> l;
	cout << "Input tinggi (t) = ";
	cin >> t;

	outLuas = 2 * (p * l + p * t + l * t);
}

float volumeTabung(int r, int t)
{
	return 3.14 * r * r * t;
}
