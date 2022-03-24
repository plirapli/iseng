#include <iostream>

using namespace std;

// [NOMOR 1]

struct Buku
{
	int kodeBuku, kodeCopyBuku;
	string judulBuku, pengarang, penerbit;
};

struct Biodata
{
	int noAnggota, noPinjam;
	string nama, alamat;
};

struct Peminjaman
{
	Biodata bio;
	Buku buku[5];
	string tglPinjam, tglHarusKembali;
};

void inputBuktiPeminjaman(Peminjaman bukti[], int &jmlBukti);

// [END NOMOR 1]

void searchTerbanyak(char arr[], int n); // [NOMOR 2]

int pangkat(int a, int b); // [NOMOR 3]

int main()
{
	// [NOMOR 1]
	Peminjaman bukti[10];
	int jmlBukti = 0;

	for (int i = 0; i < 10; i++)
		inputBuktiPeminjaman(bukti, jmlBukti);

	cout << "\n";

	// [NOMOR 2]
	char arr[] =
			{'A', 'B', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'A'};
	int ukuran = sizeof(arr) / sizeof(arr[0]);
	searchTerbanyak(arr, ukuran);

	cout << "\n";

	// [NOMOR 3]
	int a, b;
	cout << "Menghitung a pangkat b \n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << a << "^" << b << " = " << pangkat(a, b);

	return 0;
}

void inputBuktiPeminjaman(Peminjaman bukti[], int &jmlBukti) // [NOMOR 1]
{
	int jmlBuku = 0;

	cout << "BUKTI PEMINJAMAN BUKU \n";
	cout << "Nomor Anggota: ";
	cin >> bukti[jmlBukti].bio.noAnggota;
	cout << "Nama Anggota: ";
	cin.ignore();
	getline(cin, bukti[jmlBukti].bio.nama);
	cout << "Alamat Anggota: ";
	getline(cin, bukti[jmlBukti].bio.alamat);
	cout << "Nomor Pinjam: ";
	cin >> bukti[jmlBukti].bio.noPinjam;
	cout << "Tanggal Pinjam (dd-mm-yy): \n";
	cin >> bukti[jmlBukti].tglPinjam;
	cout << "Tanggal Harus Kembali (dd-mm-yy): \n";
	cin >> bukti[jmlBukti].tglHarusKembali;
	system("CLS");

	cout << "Masukkan jumlah buku yang ingin dipinjam: ";
	cin >> jmlBuku;
	for (int i = 0; i < jmlBuku; i++)
	{
		cout << "Buku " << i + 1 << ": \n";
		cout << "Kode Buku: ";
		cin >> bukti[jmlBukti].buku[jmlBuku].kodeBuku;
		cout << "Kode Copy Buku: ";
		cin >> bukti[jmlBukti].buku[jmlBuku].kodeCopyBuku;
		cout << "Judul Buku: ";
		cin >> bukti[jmlBukti].buku[jmlBuku].judulBuku;
		cout << "Pengarang: ";
		cin >> bukti[jmlBukti].buku[jmlBuku].pengarang;
		cout << "Penerbit: ";
		cin >> bukti[jmlBukti].buku[jmlBuku].penerbit;
		system("CLS");
	}
	jmlBukti++;
}

void searchTerbanyak(char arr[], int n) // [NOMOR 2]
{
	int index, indexTerbesar = 0, jml[5] = {};

	for (int i = 0; i < n; i++)
	{
		index = (arr[i] == 'A')		? 0
						: (arr[i] == 'B') ? 1
						: (arr[i] == 'C') ? 2
						: (arr[i] == 'D') ? 3
															: 4;
		jml[index]++;
	}

	// Mencari huruf terbanyak
	for (int i = 0; i < 5; i++)
		if (jml[i] > jml[indexTerbesar])
			indexTerbesar = i;

	cout << "Huruf Terbanyak: " << char(65 + indexTerbesar) << "\n";
	cout << "Jumlah: " << jml[indexTerbesar];
}

// [NOMOR 3]
int pangkat(int a, int b) { return (b > 0) ? (a * pangkat(a, b - 1)) : 1; }