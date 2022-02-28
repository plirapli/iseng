#include <iostream>
#include <string>

using namespace std;

struct Penduduk
{
	int noInduk;
	string nama, alamat;
	char gol;
};

void addRekaman(Penduduk penduduk[]);
void readRekaman(Penduduk penduduk[]);
void readRekaman(Penduduk profil[], int index);
int lsRekaman(Penduduk penduduk[], int size, int input);	// Linear Search
int lssRekaman(Penduduk penduduk[], int size, int input); // Linear Sentinel Search

int main()
{
	Penduduk rekaman[10];
	int noInduk, lsIndex, lssIndex;
	int arrSize = sizeof(rekaman) / sizeof(rekaman[0]);

	addRekaman(rekaman);
	readRekaman(rekaman);

	cout << "Cari Nomor Induk: ";
	cin >> noInduk;

	lsIndex = lsRekaman(rekaman, arrSize, noInduk);
	lssIndex = lssRekaman(rekaman, arrSize, noInduk);

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

	cout << "Terima kasih.";

	return 0;
}

void readRekaman(Penduduk penduduk[])
{
	cout << "Daftar penduduk: \n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". [" << penduduk[i].noInduk << "] "
				 << penduduk[i].nama << ", " << penduduk[i].gol
				 << " (" << penduduk[i].alamat << ") \n";
	}
	cout << "\n";
}

void readRekaman(Penduduk profil[], int index)
{
	cout << "[" << profil[index].noInduk << "] "
			 << profil[index].nama << ", " << profil[index].gol
			 << " (" << profil[index].alamat << ") \n\n";
}

void addRekaman(Penduduk penduduk[])
{
	for (int i = 0; i < 10; i++)
	{
		penduduk[i].noInduk = 123210010 + i;
		penduduk[i].nama = "Orang " + to_string(i + 1);
		penduduk[i].alamat = "Alamat " + to_string(i + 1);
		penduduk[i].gol = 65 + i;
	}
}

int lsRekaman(Penduduk penduduk[], int size, int input)
{
	for (int i = 0; i < size; i++)
		if (input == penduduk[i].noInduk)
			return i;
	return -1;
}

int lssRekaman(Penduduk penduduk[], int size, int input)
{
	int last = penduduk[size - 1].noInduk, i = 0;

	penduduk[size - 1].noInduk = input;

	while (input != penduduk[i].noInduk)
		i++;

	penduduk[size - 1].noInduk = last;

	return (i < size - 1) || (input == penduduk[size - 1].noInduk) ? i : -1;
}