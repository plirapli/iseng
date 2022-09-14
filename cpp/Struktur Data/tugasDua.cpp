#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct IngfoBuah
{
  string nama;
  int harga;
};

struct Node
{
  IngfoBuah ingfoBuah;
  Node *next;
} * awal, *akhir, *hapus, *bantu;

bool isEmpty();                      // Ngecek node kosong ga
void init();                         // Inisiasi Node
void sisipBuah(IngfoBuah ingfoBaru); // Sisip Node
void hapusBuah(string namaBuah);     // Hapus Node
void bacaMaju();                     // Baca Node dari kiri
void bacaMundur();                   // Baca Node dari kanan
int readLength();                    // Return nodes length

int main()
{
  IngfoBuah temp;
  char loop = 'y', input;

  do
  {
    system("cls");
    cout << "Data Nama Buah \n"
         << "1. Input nama buah \n"
         << "2. Lihat nama buah \n"
         << "3. Hapus buah \n"
         << "input : ";
    cin >> input;

    system("cls");
    if (input == '1')
    {
      int jml = 0;
      cout << "Banyak data : ";
      cin >> jml;

      for (int i = 0; i < jml; i++)
      {
        system("cls");

        cin.ignore();
        cout << "Nama buah   : ";
        getline(cin, temp.nama);

        cout << "Harga buah : ";
        cin >> temp.harga;

        sisipBuah(temp);
        cout << "\n[Berhasil menambahkan data!] ";
        getch();
      }
    }
    else if (input == '2')
    {
      char inputTipe;
      cout << "[1] Baca Maju \n"
           << "[2] Baca Mundur \n"
           << "[...] Kembali \n"
           << "Pilih > ";
      cin >> inputTipe;
      cout << "\n";

      switch (inputTipe)
      {
      case '1':
        bacaMaju();
        break;

      case '2':
        bacaMundur();
        break;

      default:
        break;
      }
    }
    else
    {
      string inputHapusBuah;
      bacaMaju();

      if (!isEmpty())
      {
        cin.ignore();
        cout << "Masukkan nama buah yang ingin dihapus > ";
        getline(cin, inputHapusBuah);

        hapusBuah(inputHapusBuah);
      }
    }

    cout << "Kembali ke menu ? (y/n) > ";
    cin >> loop;
  } while (loop == 'y');
}

bool isEmpty() { return awal == NULL; }

void init()
{
  awal = NULL;
  akhir = NULL;
}

void sisipBuah(IngfoBuah ingfoBaru)
{
  Node *newNode, *bantu;

  newNode = new Node;

  newNode->ingfoBuah = ingfoBaru;
  newNode->next = NULL;

  if (isEmpty())
  {
    awal = newNode;
    akhir = newNode;
  }
  else if (ingfoBaru.harga <= awal->ingfoBuah.harga) // Sisip di depan
  {
    newNode->next = awal;
    awal = newNode;
  }
  else
  {
    // Looping sampe posisi - 1
    bantu = awal;
    while (bantu->next != NULL && newNode->ingfoBuah.harga > bantu->next->ingfoBuah.harga)
      bantu = bantu->next;

    newNode->next = bantu->next; // Sisip di tengah atau di belakang
    bantu->next = newNode;

    if (ingfoBaru.harga > akhir->ingfoBuah.harga) // Jika akhir > data baru, maka akhir pindah ke data baru
      akhir = newNode;
  }
}

void hapusBuah(string namaBuah)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else if (awal->ingfoBuah.nama == namaBuah)
  {
    hapus = awal; // Hapus di awal
    awal = hapus->next;
    delete hapus;

    cout << "\n[Berhasil menghapus " << namaBuah << "!] ";
    getch();
  }
  else
  {
    // Looping sampai posisi - 1
    bantu = awal;
    while (bantu->next->next != NULL && namaBuah != bantu->next->ingfoBuah.nama)
      bantu = bantu->next;

    if (namaBuah == bantu->next->ingfoBuah.nama)
    {
      hapus = bantu->next;
      if (hapus == akhir) // Hapus di akhir
      {
        akhir = bantu;
        akhir->next = NULL;
      }
      else
        bantu->next = hapus->next; // Hapus di tengah
      delete hapus;

      cout << "\nBerhasil menghapus " << namaBuah << "! \n";
      getch();
    }
    else
      cout << "Node tidak ditemukan!\n";
  }
}

int readLength()
{
  Node *cur;

  cur = awal;
  int i = 0;
  while (cur != NULL)
  {
    cur = cur->next;
    i++;
  }

  return i;
}

void bacaMaju()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (awal == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    Node *bantu;

    bantu = awal;
    while (bantu != NULL)
    {
      cout << "Nama buah   : " << bantu->ingfoBuah.nama << "\n"
           << "Harga buah : " << bantu->ingfoBuah.harga << "\n\n";

      bantu = bantu->next;
    }
  }
  cout << "\n";
}

void bacaMundur()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (awal == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    Node *depan, *bantu;
    depan = awal;
    awal = akhir;

    do
    {
      bantu = depan;
      while (bantu->next != akhir)
        bantu = bantu->next;

      akhir->next = bantu;
      akhir = bantu;
    } while (akhir != depan);

    akhir->next = NULL;
    bantu = awal;

    // Cetak
    while (bantu != NULL)
    {
      cout << "Nama buah   : " << bantu->ingfoBuah.nama << "\n"
           << "Harga buah : " << bantu->ingfoBuah.harga << "\n\n";

      bantu = bantu->next;
    }
  }
  cout << "\n";
}