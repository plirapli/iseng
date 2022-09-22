/*Program List Dengan Array*/
#include <iostream>

#define max 12

using namespace std;

struct ingfoBuah
{
  string nama;
  int harga;
};

struct typenode
{
  ingfoBuah buah;
  int next;
} elemen[max];

int list, akhirlist, kosong, akhirkosong;

// Operasi-operasi
int listkosong();
void buatlist();
void sisipnode(ingfoBuah ingfoBaru);
void hapusnode(int ingfoHapus);
void cetaklist();

int main()
{
  ingfoBuah temp;

  buatlist();
  cetaklist();

  cout << "Masukkan nama buah: ";
  cin >> temp.nama;

  cout << "Masukkan harga buah: ";
  cin >> temp.harga;

  sisipnode(temp);
  cetaklist();

  return 0;
}
void buatlist()
{
  list = 0;
  kosong = 5;
  akhirlist = 0;
  akhirkosong = 9;

  elemen[1].next = 7;
  elemen[2].next = 3;
  elemen[3].next = 6;
  elemen[4].next = 10;
  elemen[5].next = 8;
  elemen[6].next = 1;
  elemen[7].next = 4;
  elemen[8].next = 2;
  elemen[9].next = 0;
  elemen[10].next = 9;
}

int listkosong() { return list == 0; }

void sisipnode(ingfoBuah ingfoBaru)
{
  int listbaru, k, sebelumN, n, x;

  //-------------------------- sisip di awal
  if (ingfoBaru.harga < elemen[list].buah.harga)
  {
    listbaru = kosong;                 // Data baru mengambil index kosong pertama
    kosong = elemen[kosong].next;      // Indeks kosong pindah ke next (maju 1)
    elemen[listbaru].buah = ingfoBaru; // Info data baru dimasukkan
    elemen[listbaru].next = list;      // Next data baru menunjuk ke index list awal
    list = listbaru;                   // Index list awal pindah ke index data baru
  }

  //------------------------- sisip di akhir
  else if (ingfoBaru.harga > elemen[akhirlist].buah.harga)
  {
    listbaru = kosong;                 // Data baru mengambil index kosong pertama
    kosong = elemen[kosong].next;      // Index kosong pindah ke next (maju 1)
    elemen[listbaru].buah = ingfoBaru; // Info data baru dimasukkan
    elemen[listbaru].next = 0;         // Next data baru menunjuk ke 0 (akhir dari data)
    elemen[akhirlist].next = listbaru; // Next dari list akhir menunjuk index data baru
    akhirlist = listbaru;              // Index list akhir pindah ke index data baru
  }

  //-------------------------- sisip di tengah
  else
  {
    n = list;
    x = elemen[n].buah.harga;

    // Looping sampe data yang dilooping > ingfoBaru
    while (ingfoBaru.harga > x)
    {
      sebelumN = n;             // Nyimpen index sebelum n
      n = elemen[n].next;       // Looping sampe index data yang di-looping > ingfobaru
      x = elemen[n].buah.harga; // Data yang di-looping
    }

    k = elemen[kosong].next;         // Variabel "k" menyimpan next dari index kosong
    elemen[sebelumN].next = kosong;  // Dikaitin antara variabel "sebelumN" dengan index yang mau disisipkan
    elemen[kosong].buah = ingfoBaru; // Dimasukkin datanya
    elemen[kosong].next = n;         // Next dari data baru => n (dikaitin)
    kosong = k;                      // Kosong => k
  }
}

void cetaklist()
{
  cout << list << "\n";
  if (!listkosong())
  {
    int n = list;   // Buat menyimpan index data yang ada isinya
    int m = kosong; // Buat nyimpen index data kosong

    cout << "isi list: \n"; // Cetak data
    do
    {
      cout << elemen[n].buah.nama << ", " << elemen[n].buah.harga << "\n";
      n = elemen[n].next;
    } while (elemen[n].next != 0);
    cout << elemen[n].buah.nama << ", " << elemen[n].buah.harga << "\n\n";

    cout << "Kosong : \n";
    // Cetak index doang
    do
    {
      cout << m << " ";
      m = elemen[m].next;
    } while (elemen[m].next != 0);
    cout << akhirkosong << "\n";
  }
  else
    cout << "List masih kosong! \n";
}

// void hapusnode(int ingfoHapus)
// {
//   int listbaru, k, m, n, x;

//   //------------------------ hapus di awal
//   if (ingfoHapus == elemen[list].info)
//   {
//     listbaru = elemen[list].next; // List baru menyimpdan index next dari list awal
//     k = kosong;                   // Menyimpan index kosong pertama
//     kosong = list;                // Index awal kosong pindah ke index list yang tadi dihapus (index list awal)
//     list = listbaru;              // Index list awal pindah ke list baru (maju 1)
//     elemen[kosong].next = k;      // Next index kosong => index kosong pertama yang tadi
//   }

//   //------------------ hapus di akhir
//   else if (ingfoHapus == elemen[akhirlist].info)
//   {
//     n = list;

//     k = kosong;              // Menyimpan index kosong pertama
//     kosong = akhirlist;      // Index awal kosong pindah ke index akhir list yang tadi dihapus (index list akhir)
//     elemen[kosong].next = k; // Next index kosong => index kosong pertama yang tadi

//     // Looping sampe sebelum akhir list
//     while (elemen[n].next != akhirlist)
//       n = elemen[n].next;

//     akhirlist = n;      // Index akhir list => next dari index akhir list - 1
//     elemen[n].next = 0; // Next dari index akhir list - 1 => 0
//   }

//   //------------------ hapus di tengah
//   else
//   {
//     n = list;
//     x = elemen[n].info;

//     // Looping sampe ketemu index data yang mau dihaous
//     while (elemen[n].next != 0 && ingfoHapus != x)
//     {
//       m = n;              // Nyimpen index sebelum n
//       n = elemen[n].next; // Looping sampe ketemu index data yang mau dihaous
//       x = elemen[n].info; // Data yang di-looping
//     }

//     if (ingfoHapus == elemen[n].info)
//     {
//       elemen[m].next = elemen[n].next;

//       k = kosong;              // Menyimpan index kosong pertama
//       kosong = n;              // Index awal kosong pindah ke index akhir list yang tadi dihapus (index list akhir)
//       elemen[kosong].next = k; // Next index kosong => index kosong pertama yang tadi
//     }
//     else
//       cout << "Node tidak ditemukan! \n";
//   }
// }