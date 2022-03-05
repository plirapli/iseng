#include <iostream>

using namespace std;

struct Penduduk
{
	int noInduk;
	string nama, alamat;
	char gol;
};

void addRekaman(Penduduk penduduk[], int &n);
void readRekaman(Penduduk penduduk[], int n);
void readProfil(Penduduk profil[], int index);
int lsRekaman(Penduduk penduduk[], int n, int input);	 // Linear Search
int lssRekaman(Penduduk penduduk[], int n, int input); // Linear Sentinel Search

int main()
{
	Penduduk rekaman[10];
	int pendudukAktif = 0;
	char inputMenu;

	do
	{
		cout << "Menu: \n"
				 << "[1] Tambah Penduduk \n"
				 << "[2] Lihat Daftar Penduduk \n"
				 << "[3] Cari Penduduk \n"
				 << "[Lainnya] Keluar \n"
				 << "Pilih > ";
		cin >> inputMenu;
		system("CLS");

		switch (inputMenu)
		{
		case '1':
			addRekaman(rekaman, pendudukAktif);
			break;

		case '2':
			readRekaman(rekaman, pendudukAktif);
			break;

		case '3':
		{
			int noInduk, lsIndex, lssIndex;

			readRekaman(rekaman, pendudukAktif);

			cout << "Cari Nomor Induk: ";
			cin >> noInduk;

			lsIndex = lsRekaman(rekaman, pendudukAktif, noInduk);
			lssIndex = lssRekaman(rekaman, pendudukAktif, noInduk);

			cout << "Hasil pencarian penduduk dengan NI: " << noInduk << "\n";

			cout << "1. Linear Search: ";
			if (lsIndex != -1)
				readRekaman(rekaman, lsIndex);
			else
				cout << "Tidak ditemukan. \n\n";

			cout << "2. Linear Sentinel Search: ";
			if (lssIndex != -1)
				readRekaman(rekaman, lssIndex);
			else
				cout << "Tidak ditemukan. \n\n";

			break;
		}

		default:
			inputMenu = -1;
			break;
		}
	} while (inputMenu != -1);

	cout << "Terima kasih.";

	return 0;
}

void addRekaman(Penduduk penduduk[], int &n)
{
	cout << "Tambah Penduduk \n";
	cout << "Nomor Induk: ";
	cin >> penduduk[n].noInduk;

	cout << "Nama: ";
	cin.ignore();
	getline(cin, penduduk[n].nama);

	cout << "Alamat: ";
	getline(cin, penduduk[n].alamat);

	cout << "Gol: ";
	cin >> penduduk[n].gol;

	cout << "Penduduk berhasil ditambahkan. \n\n";

	n++;
}

void readRekaman(Penduduk penduduk[], int n)
{
	cout << "Daftar penduduk: \n";
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". [" << penduduk[i].noInduk << "] "
					 << penduduk[i].nama << ", " << penduduk[i].gol
					 << " (" << penduduk[i].alamat << ") \n";
		}
	}
	else
		cout << "Penduduk belum ada. \n";

	cout << "\n";
}

void readProfil(Penduduk profil[], int index)
{
	cout << "[" << profil[index].noInduk << "] "
			 << profil[index].nama << ", " << profil[index].gol
			 << " (" << profil[index].alamat << ") \n\n";
}

int lsRekaman(Penduduk penduduk[], int n, int input)
{
	for (int i = 0; i < n; i++)
		if (input == penduduk[i].noInduk)
			return i;
	return -1;
}

int lssRekaman(Penduduk penduduk[], int n, int input)
{
	int last = penduduk[n - 1].noInduk, i = 0;

	penduduk[n - 1].noInduk = input;
	while (input != penduduk[i].noInduk)
		i++;
	penduduk[n - 1].noInduk = last;

	return (i < n - 1) || (input == penduduk[n - 1].noInduk) ? i : -1;
}