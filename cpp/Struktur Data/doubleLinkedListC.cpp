#include <bits/stdc++.h>

using namespace std;

typedef int Ingfo;

struct Node
{
  Ingfo ingfo;
  Node *prev;
  Node *next;
} * awal, *akhir;

bool isEmpty() { return awal == NULL; }

void create()
{
  awal = NULL;
  akhir = NULL;
}

void sisipNode(Ingfo newIngfo)
{
  Node *newNode, *bantu;

  newNode = new Node;
  newNode->ingfo = newIngfo;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (isEmpty())
  {
    awal = newNode;
    akhir = newNode;
  }
  else if (newIngfo <= awal->ingfo) // Sisip di depan
  {
    newNode->next = awal;
    awal->prev = newNode;
    awal = newNode;
  }
  else
  {
    // Looping sampe posisi - 1
    bantu = awal;
    while (bantu->next != NULL && newIngfo > bantu->next->ingfo)
      bantu = bantu->next;

    // 5, 20, 50, 99
    //  10
    newNode->next = bantu->next; // Sisip di tengah atau di belakang
    bantu->next = newNode;
    newNode->prev = bantu;

    // Jika data di akhir, maka akhir pindah ke data baru
    // Jika sisip tengah, maka kiri dari next bantu = node baru
    if (newNode->next == NULL)
      akhir = newNode;
    else
      newNode->next->prev = newNode;
  }
}

void hapusNode(Ingfo delIngfo)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else if (awal->ingfo == delIngfo) // Hapus di awal
  {
    hapus = awal;
    awal = hapus->next;
    awal->prev = NULL;
    delete hapus;
  }
  else
  {
    // Looping sampai posisi - 1
    bantu = awal;
    while (bantu->next != NULL && delIngfo != bantu->next->ingfo)
      bantu = bantu->next;

    if (delIngfo == bantu->next->ingfo)
    {
      hapus = bantu->next;
      bantu->next = hapus->next; // Hapus di tengah

      if (hapus == akhir) // Hapus di akhir
        akhir = bantu;
      else
        hapus->next->prev = bantu;
      delete hapus;
    }
    else
      cout << "Node tidak ditemukan!\n";
  }
}

int readLength()
{
  Node *bantu;

  bantu = awal;
  int i = 0;
  while (bantu != NULL)
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
    Node *bantu;

    bantu = awal;
    while (bantu != NULL)
    {
      cout << bantu->ingfo << ", ";
      bantu = bantu->next;
    }
  }
  cout << "\n";
}

void cetakBelakang()
{
  cout << "Jumlah data: " << readLength() << "\n";
  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    Node *depan, *bantu;

    bantu = akhir;
    while (bantu != NULL)
    {
      cout << bantu->ingfo << ", ";
      bantu = bantu->prev;
    }
  }
  cout << "\n";
}

int main()
{
  cout << "List Mula-mula : \n";
  create();
  sisipNode(50);
  sisipNode(20);
  sisipNode(5);
  sisipNode(99);
  sisipNode(10);
  cetakDepan();

  cout << "\nHapus node 5, 50, 99 \n";
  cout << "Kodisi List setelah di hapus, dibaca dari belakang :\n";
  hapusNode(50);
  hapusNode(99);
  hapusNode(5);
  sisipNode(13);
  cetakBelakang();

  return 0;
}