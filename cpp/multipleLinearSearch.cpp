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
void readProfil(Penduduk profil[], int *res);
int *search(Penduduk penduduk[], int n, int input);

int main()
{
	Penduduk rekaman[10];
	int pendudukAktif = 0;
	char inputMenu;

	// Populate rekaman
	addRekaman(rekaman, pendudukAktif);

	do
	{
		cout << "Menu: \n"
				 << "[1] Lihat Daftar Penduduk \n"
				 << "[2] Cari Penduduk \n"
				 << "[...] Keluar \n"
				 << "Pilih > ";
		cin >> inputMenu;
		system("CLS");

		switch (inputMenu)
		{
		case '1':
			readRekaman(rekaman, pendudukAktif);
			break;

		case '2':
		{
			char gol;
			int *searchRes;
			readRekaman(rekaman, pendudukAktif);

			cout << "Cari Goldar: ";
			cin >> gol;

			searchRes = search(rekaman, pendudukAktif, gol);

			cout << "Hasil pencarian penduduk dengan Goldar: " << gol << "\n";

			if (searchRes[1] != 0)
			{
				for (int i = 0; i < 3; i++)
				{
					cout << "[" << rekaman[*(searchRes + i)].noInduk << "] "
							 << rekaman[searchRes[i]].nama << ", "
							 << rekaman[searchRes[i]].gol
							 << " (" << rekaman[searchRes[i]].alamat << ") \n";
				}
				cout << "\n";
			}
			else
				cout << "Tidak ditemukan. \n\n";

			// Menghapus memory agar hasil pencarian tidak terulang.
			delete[] searchRes;
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
	for (int i = 0; i < 6; i++)
	{
		penduduk[n].noInduk = 12321000 + i;
		penduduk[n].nama = "Orang";
		penduduk[n].alamat = "Alamat";
		penduduk[n].gol = (n % 2 == 0) ? 'A' : 'B';

		n++;
	}
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

int *search(Penduduk penduduk[], int n, int input)
{
	int *res = new int[100];
	int resIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (input == penduduk[i].gol)
		{
			res[resIndex] = i;
			resIndex++;
		}
	}

	return res;
}