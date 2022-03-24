#include <iostream>

using namespace std;

// // [NOMOR 1]

// struct Tgl
// {
// 	int hari, bulan, tahun;
// };

// struct Buku
// {
// 	int kodeBuku, kodeCopyBuku;
// 	string judulBuku, pengarang, penerbit;
// };

// struct Biodata
// {
// 	int noAnggota, noPinjam;
// 	string nama, alamat;
// };

// struct Peminjaman
// {
// 	Biodata bio;
// 	Buku buku[5];
// 	Tgl tglPinjam, tglHarusKembali;
// };

// void inputBuktiPeminjaman(Peminjaman buktiPeminjaman[], int &jmlBukti);

// // [END NOMOR 1]

// void searchTerbanyak(char arr[], int n); // [NOMOR 2]

int rR(int n); // [NOMOR 3 bagian 8]

int main()
{
	// // [NOMOR 1]
	// Peminjaman buktiPeminjaman[10];
	// int jmlBukti = 0;

	// inputBuktiPeminjaman(buktiPeminjaman, jmlBukti);

	// [NOMOR 2]
	// char arr[] =
	// 		{'A', 'B', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E', 'A', 'A'};
	// int ukuran = sizeof(arr) / sizeof(arr[0]);

	// searchTerbanyak(arr, ukuran);

	// [NOMOR 3]
	int n;
	cout << "Masukkan n: ";
	cin >> n;
	rR(n);

	return 0;
}

// void inputBuktiPeminjaman(Peminjaman buktiPeminjaman[], int &jmlBukti) // [NOMOR 1]
// {
// 	int jmlBuku = 0;
//
// 	cout << "BUKTI PEMINJAMAN BUKU \n";
// 	cout << "Nomor Anggota: ";
// 	cin >> buktiPeminjaman[jmlBukti].bio.noAnggota;
// 	cout << "Nama Anggota: ";
// 	cin.ignore();
// 	getline(cin, buktiPeminjaman[jmlBukti].bio.nama);
// 	cout << "Alamat Anggota: ";
// 	getline(cin, buktiPeminjaman[jmlBukti].bio.alamat);
// 	cout << "Nomor Pinjam: ";
// 	cin >> buktiPeminjaman[jmlBukti].bio.noPinjam;
//
// 	cout << "Tanggal Pinjam: \n";
// 	cout << "Hari: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglPinjam.hari;
// 	cout << "Bulan: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglPinjam.bulan;
// 	cout << "Tahun: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglPinjam.tahun;
//
// 	cout << "Tanggal Harus Kembali: \n";
// 	cout << "Hari: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglHarusKembali.hari;
// 	cout << "Bulan: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglHarusKembali.bulan;
// 	cout << "Tahun: ";
// 	cin >> buktiPeminjaman[jmlBukti].tglHarusKembali.tahun;
//
// 	cout << "Masukkan jumlah buku yang ingin dipinjam: ";
// 	cin >> jmlBuku;
// 	for (int i = 0; i < jmlBuku; i++)
// 	{
// 		cout << "Buku " << i + 1 << ": \n";
// 		cout << "Kode Buku: ";
// 		cin >> buktiPeminjaman[jmlBukti].buku[jmlBuku].kodeBuku;
// 		cout << "Kode Copy Buku: ";
// 		cin >> buktiPeminjaman[jmlBukti].buku[jmlBuku].kodeCopyBuku;
// 		cout << "Judul Buku: ";
// 		cin >> buktiPeminjaman[jmlBukti].buku[jmlBuku].judulBuku;
// 		cout << "Pengarang: ";
// 		cin >> buktiPeminjaman[jmlBukti].buku[jmlBuku].pengarang;
// 		cout << "Penerbit: ";
// 		cin >> buktiPeminjaman[jmlBukti].buku[jmlBuku].penerbit;
// 	}
// 	jmlBukti++;
// }

// void searchTerbanyak(char arr[], int n) // [NOMOR 2]
// {
// 	char huruf[5] = {'A', 'B', 'C', 'D', 'E'};
// 	char hurufTerbanyak = huruf[0];
// 	int jml[5] = {};
// 	int jmlHurufTerbanyak = jml[0];
//
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (arr[i] == 'A')
// 			jml[0]++;
// 		else if (arr[i] == 'B')
// 			jml[1]++;
// 		else if (arr[i] == 'C')
// 			jml[2]++;
// 		else if (arr[i] == 'D')
// 			jml[3]++;
// 		else if (arr[i] == 'E')
// 			jml[4]++;
// 	}
//
// 	// Mencari huruf terbanyak
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (jml[i] > jmlHurufTerbanyak)
// 		{
// 			jmlHurufTerbanyak = jml[i];
// 			hurufTerbanyak = huruf[i];
// 		}
// 	}
// 	cout << "Nilai terbesar: " << hurufTerbanyak << "\n";
// 	cout << "Jumlah: " << jmlHurufTerbanyak;
// }

int rR(int n) // [NOMOR 3 bagian 8]
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return -1 * rR(n - 1) + 2 * rR(n - 2);
}