#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int i, ukuran = 5, hapus;
char pilih;
bool ketemu = false;
string fitur[] = {"tambah", "cari", "tampil", "hapus"}, cari_nama;
struct data_penduduk
{
    string nama[10] = {"Siapa Saya", "Siapa Kamu", "Siapa Anda", "Siapa Mereka", "Kamu Siapa"};
    string alamat[10] = {"Jl. Aspal", "Jl. Berlubang", "Jl. Berair", "Jl. Bergelombang", "Jl. Kerikil"};
    int umur[10] = {17, 18, 20, 32, 15};
    string agama[10] = {"Islam", "Katolik", "Islam", "Islam", "Buddha"};
    string goldar[10] = {"A", "AB", "O", "O", "B"};
    string status[10] = {"belum kawin", "sudah kawin", "belum kawin", "belum kawin", "sudah kawin"};
};
void tampil_menu(struct data_penduduk info_penduduk)
{
    cout << "=======================================================================================================\n";
    cout << "| " << setiosflags(ios::left) << setw(3) << "No"
         << "| " << setw(20) << "Nama"
         << "| " << setw(20) << "Alamat"
         << "| " << setw(5) << "Umur"
         << "| " << setw(18) << "Agama"
         << "| "
         << setw(7) << "Goldar"
         << "| " << setw(15) << "Status"
         << "|" << endl;
    cout << "=======================================================================================================\n";

    for (i = 0; i < ukuran; i++)
    {
        cout << "| " << setiosflags(ios::left) << setw(3) << i + 1 << "| " << setw(20) << info_penduduk.nama[i] << "| " << setw(20) << info_penduduk.alamat[i] << "| " << setw(5) << info_penduduk.umur[i] << "| " << setw(18) << info_penduduk.agama[i] << "| "
             << setw(7) << info_penduduk.goldar[i] << "| " << setw(15) << info_penduduk.status[i] << "|" << endl;
    }
    cout << "=======================================================================================================\n";
}

int main()
{
    data_penduduk penduduk;
    for (i = 0; i < 4; i++)
    {
        cout << "[" << i + 1 << "] " << fitur[i] << endl;
    }
    cout << "pilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case '1':
        tampil_menu(penduduk);
        cin.ignore();
        do
        {
            cout << "Masukkan nama\t: ";
            getline(cin, penduduk.nama[ukuran]);
            cout << "Masukkan alamat\t: ";
            getline(cin, penduduk.alamat[ukuran]);
            cout << "Masukkan umur\t: ";
            cin >> penduduk.umur[ukuran];
            cin.ignore();
            cout << "Masukkan agama\t: ";
            getline(cin, penduduk.agama[ukuran]);
            cout << "Masukkan goldar\t: ";
            getline(cin, penduduk.goldar[ukuran]);
            cout << "Masukkan status\t: ";
            getline(cin, penduduk.status[ukuran]);
            ukuran++;
            tampil_menu(penduduk);
            cout << "lagi ? ";
            cin >> pilih;
            cin.ignore();
        } while (pilih == 'y');
        break;
    case '2':
        cout << "Cari Nama : ";
        cin.ignore();
        getline(cin, cari_nama);
        i = 0;
        while ((i < ukuran) && (ketemu == false))
        {
            if (penduduk.nama[i] == cari_nama)
            {
                ketemu = true;
            }
            else
            {
                i++;
            }
        }
        if (ketemu == true)
        {
            cout << "data ditemukan\n";
            cout << "Nama\t: " << penduduk.nama[i] << endl;
            cout << "Alamat\t: " << penduduk.alamat[i] << endl;
            cout << "Umur\t: " << penduduk.umur[i] << endl;
            cout << "Agama\t: " << penduduk.agama[i] << endl;
            cout << "Goldar\t: " << penduduk.goldar[i] << endl;
            cout << "Status\t: " << penduduk.status[i] << endl;
        }
        else
        {
            cout << "data tidak ditemukan";
        }
        break;
    case '3':
        tampil_menu(penduduk);
        break;
    case '4':
        do
        {
            tampil_menu(penduduk);
            cout << "Data yang ingin dihapus(nomor) : ";
            cin >> hapus;
            for (i = hapus - 1; i < ukuran; i++)
            {
                penduduk.nama[i] = penduduk.nama[i + 1];
                penduduk.alamat[i] = penduduk.alamat[i + 1];
                penduduk.umur[i] = penduduk.umur[i + 1];
                penduduk.agama[i] = penduduk.agama[i + 1];
                penduduk.goldar[i] = penduduk.goldar[i + 1];
                penduduk.status[i] = penduduk.status[i + 1];
            }
            ukuran--;
            tampil_menu(penduduk);
            cout << "lagi ? ";
            cin >> pilih;
        } while (pilih == 'y');
        break;
    }
}