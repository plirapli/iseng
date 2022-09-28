#include <iostream>
#include <conio.h>

using namespace std;

struct IngfoBuah
{
  string nama;
  int harga;
};

struct Node
{
  IngfoBuah Buah;
  Node *next;
} * head, *tail;

bool isEmpty() { return head->next == tail; }

void create()
{
  head = new Node;
  tail = new Node;

  head->Buah.harga = -2147483647;
  head->next = tail;

  tail->Buah.harga = 2147483647;
  tail->next = NULL;
}

void sisipNode(IngfoBuah newIngfo)
{
  Node *newNode, *bantu;

  newNode = new Node;
  newNode->Buah = newIngfo;

  // Looping sampe posisi - 1
  bantu = head;
  while (newIngfo.harga > bantu->next->Buah.harga)
    bantu = bantu->next;

  newNode->next = bantu->next; // Sisip di tengah
  bantu->next = newNode;
}

void hapusNode(string namaBuah)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else
  {
    // Looping sampai posisi - 1
    bantu = head;
    while (bantu->next != tail && namaBuah != bantu->next->Buah.nama)
      bantu = bantu->next;

    if (namaBuah == bantu->next->Buah.nama)
    {
      hapus = bantu->next;
      bantu->next = hapus->next;
      delete hapus;

      cout << "\nBerhasil menghapus " << namaBuah << "! \n";
    }
    else
      cout << "Node tidak ditemukan!\n";
  }
}

int readLength()
{
  Node *bantu;

  // Looping sampe sebelum tail
  bantu = head->next;
  int i = 0;
  while (bantu != tail)
  {
    bantu = bantu->next;
    i++;
  }

  return i;
}

void cetakDepan()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    Node *depan, *bantu;

    // Biar kalo abis cetak mundur, urutannya dibalikin lagi
    if (head->Buah.harga > head->next->Buah.harga)
    {
      depan = head;
      head = tail;

      do
      {
        bantu = depan;
        while (bantu->next != tail)
          bantu = bantu->next;

        tail->next = bantu;
        tail = bantu;
      } while (tail != depan);

      tail->next = NULL;
    }

    // Looping sampe sebelum tail
    bantu = head->next;
    while (bantu != tail)
    {
      cout << bantu->Buah.nama << ", Rp"
           << bantu->Buah.harga << "\n";
      bantu = bantu->next;
    }
  }
  cout << "\n";
}

void cetakMundur()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    Node *depan, *bantu;

    // Kalo sebelumnya dah dibalik, gausah dibalik lagi urutannya
    if (head->Buah.harga < head->next->Buah.harga)
    {
      depan = head;
      head = tail;

      do
      {
        bantu = depan;
        while (bantu->next != tail)
          bantu = bantu->next;

        tail->next = bantu;
        tail = bantu;
      } while (tail != depan);

      tail->next = NULL;
    }

    // Cuman nyetak doang
    bantu = head->next;
    while (bantu != tail)
    {
      cout << bantu->Buah.nama << ", Rp"
           << bantu->Buah.harga << "\n";
      bantu = bantu->next;
    }
  }
  cout << "\n";
}

void pressAnyKey()
{
  cout << "[Tekan tombol apa saja untuk melanjutkan.]";
  getch();
}

int main()
{
  IngfoBuah temp;
  bool loop = 1;
  char input;

  create();

  do
  {
    system("cls");
    cout << "Data Nama Buah \n"
         << "[1] Input nama buah \n"
         << "[2] Lihat nama buah \n"
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

        sisipNode(temp);
        cout << "\nBerhasil menambahkan data! \n";
        pressAnyKey();
      }
      break;
    }

    case '2':
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
        cetakDepan();
        pressAnyKey();
        break;

      case '2':
        cetakMundur();
        pressAnyKey();
        break;

      default:
        break;
      }
      break;
    }

    case '3':
    {
      string inputHapusBuah;
      cetakDepan();

      if (!isEmpty())
      {
        cin.ignore();
        cout << "Masukkan nama buah yang ingin dihapus > ";
        getline(cin, inputHapusBuah);

        hapusNode(inputHapusBuah);
        pressAnyKey();
      }
      break;
    }

    default:
      loop = 0;
      break;
    }
  } while (loop);
}