/*Program List Dengan Array*/
#include <iostream>

#define max 12

using namespace std;

struct typenode
{
  int info;
  int next;
} elemen[max];

int list, akhirlist, kosong, akhirkosong;

// Operasi-operasi
int listkosong();
void buatlist();
void sisipnode(int ingfoBaru);
void hapusnode(int ingfoHapus);
void cetaklist();

int main()
{
  buatlist();
  cetaklist();

  sisipnode(7);
  cout << "\n\n Sisip 7 \n\n";
  cetaklist();

  sisipnode(30);
  cout << "\n\n sisip 30 \n\n";
  cetaklist();

  hapusnode(7);
  cout << "\n\n hapus 7 \n\n";
  cetaklist();

  return 0;
}
void buatlist()
{
  list = 5;
  kosong = 3;
  akhirlist = 10;
  akhirkosong = 4;

  elemen[1].info = 25;
  elemen[1].next = 8;
  elemen[2].info = 0;
  elemen[2].next = 9;
  elemen[3].info = 0;
  elemen[3].next = 6;
  elemen[4].info = 0;
  elemen[4].next = 0;
  elemen[5].info = 10;
  elemen[5].next = 7;
  elemen[6].info = 0;
  elemen[6].next = 2;
  elemen[7].info = 15;
  elemen[7].next = 1;
  elemen[8].info = 40;
  elemen[8].next = 10;
  elemen[9].info = 0;
  elemen[9].next = 4;
  elemen[10].info = 60;
  elemen[10].next = 0;
}
int listkosong() { return list == 0; }

void sisipnode(int ingfoBaru)
{
  int listbaru, k, m, n, x;

  //-------------------------- sisip di awal
  if (ingfoBaru < elemen[list].info)
  {
    listbaru = kosong;                 // Data baru mengambil index kosong pertama
    kosong = elemen[kosong].next;      // Indeks kosong pindah ke next (maju 1)
    elemen[listbaru].info = ingfoBaru; // Info data baru dimasukkan
    elemen[listbaru].next = list;      // Next data baru menunjuk ke index list awal
    list = listbaru;                   // Index list awal pindah ke index data baru
  }

  //------------------------- sisip di akhir
  else if (ingfoBaru > elemen[akhirlist].info)
  {
    listbaru = kosong;                 // Data baru mengambil index kosong pertama
    kosong = elemen[kosong].next;      // Index kosong pindah ke next (maju 1)
    elemen[listbaru].info = ingfoBaru; // Info data baru dimasukkan
    elemen[listbaru].next = 0;         // Next data baru menunjuk ke 0 (akhir dari data)
    elemen[akhirlist].next = listbaru; // Next dari list akhir menunjuk index data baru
    akhirlist = listbaru;              // Index list akhir pindah ke index data baru
  }

  //-------------------------- sisip di tengah
  else
  {
    n = list;
    x = elemen[n].info;

    // Looping sampe data yang dilooping > ingfoBaru
    while (ingfoBaru > x)
    {
      m = n;              // Nyimpen index sebelum n
      n = elemen[n].next; // Looping sampe index data yang di-looping > ingfobaru
      x = elemen[n].info; // Data yang di-looping
    }

    k = elemen[kosong].next;         // Variabel "k" menyimpan next dari index kosong
    elemen[m].next = kosong;         // Dikaitin
    elemen[kosong].info = ingfoBaru; // Dimasukkin datanya
    elemen[kosong].next = n;         // Next dari data baru => n (dikaitin)
    kosong = k;                      // Kosong => k
  }
}

void cetaklist()
{
  int n = list;   // Buat menyimpan index data yang ada isinya
  int m = kosong; // Buat nyimpen index data kosong

  cout << "isi list : \n"; // Cetak data
  do
  {
    cout << elemen[n].info << " ";
    n = elemen[n].next;
  } while (elemen[n].next != 0);
  cout << " " << elemen[akhirlist].info << endl;

  cout << "\nIndex tempat-tempat kosong: \n"; // Cetak index doang
  do
  {
    cout << m << " ";
    m = elemen[m].next;
  } while (elemen[m].next != 0);
  cout << " " << akhirkosong;
}

void hapusnode(int ingfoHapus)
{
  int listbaru, k, m, n, x;

  //------------------------ hapus di awal
  if (ingfoHapus == elemen[list].info)
  {
    listbaru = elemen[list].next; // List baru menyimpdan index next dari list awal
    k = kosong;                   // Menyimpan index kosong pertama
    kosong = list;                // Index awal kosong pindah ke index list yang tadi dihapus (index list awal)
    list = listbaru;              // Index list awal pindah ke list baru (maju 1)
    elemen[kosong].next = k;      // Next index kosong => index kosong pertama yang tadi
  }

  //------------------hapus di akhir
  else if (ingfoHapus == elemen[akhirlist].info)
  {
    n = list;

    k = kosong;              // Menyimpan index kosong pertama
    kosong = akhirlist;      // Index awal kosong pindah ke index akhir list yang tadi dihapus (index list akhir)
    elemen[kosong].next = k; // Next index kosong => index kosong pertama yang tadi

    // Looping sampe sebelum akhir list
    while (elemen[n].next != akhirlist)
      n = elemen[n].next;

    akhirlist = n;      // Index akhir list => next dari index akhir list - 1
    elemen[n].next = 0; // Next dari index akhir list - 1 => 0
  }

  //------------------hapus di tengah
  else
  {
    n = list;
    x = elemen[n].info;

    // Looping sampe data yang dilooping > ingfoBaru
    while (elemen[n].next != 0 && ingfoHapus != x)
    {
      m = n;              // Nyimpen index sebelum n
      n = elemen[n].next; // Looping sampe index data yang di-looping > ingfobaru
      x = elemen[n].info; // Data yang di-looping
    }

    if (ingfoHapus == elemen[n].info)
    {
      elemen[m].next = elemen[n].next;

      k = kosong;              // Menyimpan index kosong pertama
      kosong = n;              // Index awal kosong pindah ke index akhir list yang tadi dihapus (index list akhir)
      elemen[kosong].next = k; // Next index kosong => index kosong pertama yang tadi
    }
    else
      cout << "Node tidak ditemukan! \n";

    // buat sendiri!! untuk TUGAS
  }
}