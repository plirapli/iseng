#include <iostream>
#include <vector>

using namespace std;

char angkaKeHuruf(int nilai);

struct mahasiswa
{
	int noMhs, nilaiAngka;
	char kelas, nilaiHuruf = angkaKeHuruf(nilaiAngka);
	string nama;
} Mhs[5];

int main()
{

	Mhs[0].noMhs = 123210078;
	Mhs[0].nama = "John Doe";
	Mhs[0].kelas = 'C';
	Mhs[0].nilaiAngka = 20;

	for (int i = 0; i < 5; i++)
	{
		cout << "Mahasiswa ke-" << i + 1 << ": \n"
				 << "NIM \t: " << Mhs[i].noMhs << "\n"
				 << "Nama \t: " << Mhs[i].nama << "\n"
				 << "Kelas \t: " << Mhs[i].kelas << "\n"
				 << "Nilai \t: " << Mhs[i].nilaiAngka << " (" << Mhs[i].nilaiHuruf << ") \n\n";
	}

	return 0;
}

char angkaKeHuruf(int nilai)
{
	char huruf;

	switch (nilai)
	{
	case 75 ... 100:
		huruf = 'A';
		break;
	case 60 ... 74:
		huruf = 'B';
		break;
	case 40 ... 59:
		huruf = 'C';
		break;
	case 20 ... 39:
		huruf = 'D';
		break;
	case 0 ... 19:
		huruf = 'E';
		break;
	default:
		huruf = '-';
		break;
	}

	return huruf;
}