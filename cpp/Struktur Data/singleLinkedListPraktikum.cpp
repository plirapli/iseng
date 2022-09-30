#include <bits/stdc++.h>

using namespace std;

typedef int Ingfo;

struct Node
{
  Ingfo ingfo;
  Node *next;
} * awal, *akhir;

bool isEmpty() { return awal == NULL; }

void init()
{
  awal = NULL;
  akhir = NULL;
}

void sisipNode(Ingfo newIngfo)
{
  Node *newNode, *bantu;

  newNode = new Node;

  newNode->ingfo = newIngfo;
  newNode->next = NULL;

  if (isEmpty())
  {
    awal = newNode;
    akhir = newNode;
  }
  else if (newIngfo <= awal->ingfo) // Sisip di depan
  {
    newNode->next = awal;
    awal = newNode;
  }
  else
  {
    // Looping sampe posisi - 1
    bantu = awal;
    while (bantu->next != NULL && newNode->ingfo > bantu->next->ingfo)
      bantu = bantu->next;

    newNode->next = bantu->next; // Sisip di tengah atau di belakang
    bantu->next = newNode;

    if (newIngfo > akhir->ingfo) // Jika akhir > data baru, maka akhir pindah ke data baru
      akhir = newNode;
  }
}

void hapusNode(Ingfo delIngfo)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else if (awal->ingfo == delIngfo)
  {
    hapus = awal; // Hapus di awal
    awal = hapus->next;
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
      if (hapus == akhir) // Hapus di akhir
      {
        akhir = bantu;
        akhir->next = NULL;
      }
      else
        bantu->next = hapus->next; // Hapus di tengah

      delete hapus;
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

void readForward()
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

void readBackward()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (awal == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    Node *depan, *cur;
    depan = awal;
    awal = akhir;

    do
    {
      cur = depan;
      while (cur->next != akhir)
        cur = cur->next;

      akhir->next = cur;
      akhir = cur;
    } while (akhir != depan);

    akhir->next = NULL;
    cur = awal;

    // Cetak
    while (cur != NULL)
    {
      cout << cur->ingfo << ", ";
      cur = cur->next;
    }
  }
  cout << "\n";
}

int main()
{
  cout << "List Mula-mula : \n";
  init();
  sisipNode(50);
  sisipNode(20);
  sisipNode(5);
  sisipNode(99);
  sisipNode(10);
  readForward();

  cout << "\n\nHapus node 50 \n";
  cout << "\nKodisi List setelah di hapus, dibaca dari belakang :\n";

  hapusNode(50);
  readBackward();

  return 0;
}