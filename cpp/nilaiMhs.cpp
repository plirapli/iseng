#include <iostream>
#include <iomanip>

using namespace std;

struct komponen
{
	int no, skor;
	string nama;
};

struct mahasiswa
{
	int noMhs, jmlKomponen;
	string nama, matKul;
	komponen komp[10];
} mhs[2];

int main()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Mahasiswa ke-" << i + 1 << ": \n";
		cout << "NIM \t: ";
		cin >> mhs[i].noMhs;
		cin.ignore();

		cout << "Nama \t: ";
		getline(cin, mhs[i].nama);

		cout << "Mata Kuliah : ";
		getline(cin, mhs[i].matKul);

		cout << "Banyak Komponen : ";
		cin >> mhs[i].jmlKomponen;
		cout << "\n";

		for (int j = 0; j < mhs[i].jmlKomponen; j++)
		{
			cout << "Komponen ke-" << j + 1 << ": \n";
			cout << "No \t: ";
			cin >> mhs[i].komp[j].no;
			cin.ignore();

			cout << "Nama \t: ";
			getline(cin, mhs[i].komp[j].nama);

			cout << "Skor \t: ";
			cin >> mhs[i].komp[j].skor;
			cout << "\n";
		}
		system("CLS");
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "NIM \t: " << mhs[i].noMhs << "\n"
				 << "Nama \t: " << mhs[i].nama << "\n"
				 << "Mata kuliah : " << mhs[i].matKul << "\n";

		cout << left
				 << setw(4) << "No"
				 << setw(15) << "Nama Komponen"
				 << setw(7) << "Nilai"
				 << "\n";

		for (int j = 0; j < mhs[i].jmlKomponen; j++)
		{
			cout << left
					 << setw(4) << mhs[i].komp[j].no
					 << setw(15) << mhs[i].komp[j].nama
					 << setw(7) << mhs[i].komp[j].skor
					 << "\n";
		}
		cout << "\n";
	}

	return 0;
}