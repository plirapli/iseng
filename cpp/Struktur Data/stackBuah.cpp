#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct buah
{
	string nama;
	int harga;
};

struct Stack
{
	buah infoBuah;
	Stack *kiri, *kanan;
} * stackAwal, *stackAkhir;

void buat();
void push(buah newInfo);
void pop();
void cetak();

// Cek kondisi stack
int isEmpty() { return stackAwal == NULL; }

void pressAnyKey()
{
	cout << "[Tekan tombol apa saja untuk melanjutkan.]";
	getch();
}

int main()
{
	buah temp;
	char input;
	bool loop = 1;

	buat();
	do
	{
		system("cls");
		cout << "Data Nama Buah \n"
				 << "[1] Input buah \n"
				 << "[2] Lihat buah \n"
				 << "[3] Hapus buah \n"
				 << "[...] Kembali \n"
				 << "Input > ";
		cin >> input;

		system("cls");
		switch (input)
		{
		case '1':
		{
			int jml = 0;
			cout << "Banyak data > ";
			cin >> jml;

			for (int i = 0; i < jml; i++)
			{
				system("cls");

				cin.ignore();
				cout << "Nama buah > ";
				getline(cin, temp.nama);

				cout << "Harga buah > ";
				cin >> temp.harga;

				push(temp);
				cout << "\nBerhasil menambahkan data! \n";
				pressAnyKey();
			}
			break;
		}

		case '2':
			cetak();
			pressAnyKey();
			break;

		case '3':
			pop();
			break;

		default:
			loop = 0;
			break;
		}
	} while (loop);

	return 0;
}

void buat()
{
	Stack *NS;

	NS = new Stack;
	NS = NULL;

	stackAwal = NS;
	stackAkhir = NS;
}

void push(buah newInfo)
{
	Stack *NS;

	NS = new Stack;
	NS->infoBuah = newInfo;
	NS->kiri = NULL;
	NS->kanan = NULL;

	if (stackAwal == NULL)
	{
		stackAwal = NS;
		stackAkhir = NS;
	}
	else
	{
		stackAwal->kanan = NS;
		NS->kiri = stackAwal;
		stackAwal = NS;
	}
}

void pop()
{
	Stack *hapus;

	if (isEmpty())
		cout << "Stack kosong! \n";
	else
	{
		hapus = stackAwal;
		stackAwal = stackAwal->kiri;
		stackAwal->kanan = NULL;
		delete hapus;
	}
}

void cetak()
{
	Stack *bantu;

	bantu = stackAwal;
	while (bantu != NULL)
	{
		cout << bantu->infoBuah.nama << "(Rp" << bantu->infoBuah.harga << ")" << '\n';
		bantu = bantu->kiri;
	}
}
