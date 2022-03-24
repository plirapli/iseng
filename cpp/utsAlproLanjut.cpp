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
	inputBuktiPeminjaman(bukti, jmlBukti);

	// [NOMOR 2]
	char arr[] =
			{'A', 'B', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'A'};
	int ukuran = sizeof(arr) / sizeof(arr[0]);
	searchTerbanyak(arr, ukuran);

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
	}
	jmlBukti++;
}

void searchTerbanyak(char arr[], int n) // [NOMOR 2]
{
	char huruf[5] = {'A', 'B', 'C', 'D', 'E'};
	int jml[5] = {};
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 'A')
			jml[0]++;
		else if (arr[i] == 'B')
			jml[1]++;
		else if (arr[i] == 'C')
			jml[2]++;
		else if (arr[i] == 'D')
			jml[3]++;
		else if (arr[i] == 'E')
			jml[4]++;
	}

	// Mencari huruf terbanyak
	for (int i = 0; i < 5; i++)
		if (jml[i] > jml[index])
			index = i;

	cout << "Huruf Terbanyak: " << huruf[index] << "\n";
	cout << "Jumlah: " << jml[index];
}

int pangkat(int a, int b) { return (b > 0) ? (a * pangkat(a, b - 1)) : 1; }