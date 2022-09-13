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
  Node *newNode, *cur;

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
    cur = awal;
    while (cur->next != NULL && newNode->ingfo > cur->next->ingfo)
      cur = cur->next;

    newNode->next = cur->next; // Sisip di tengah atau di belakang
    cur->next = newNode;

    if (newIngfo > akhir->ingfo) // Jika akhir > data baru, maka akhir pindah ke data baru
      akhir = newNode;
  }
}

void hapusNode(Ingfo delIngfo)
{
  Node *hapus, *cur;

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
    cur = awal;
    while (cur->next->next != NULL && delIngfo != cur->next->ingfo)
      cur = cur->next;

    if (delIngfo == cur->next->ingfo)
    {
      hapus = cur->next;
      if (hapus == akhir) // Hapus di akhir
      {
        akhir = cur;
        akhir->next = NULL;
      }
      else
        cur->next = hapus->next; // Hapus di tengah
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

  if (awal == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    Node *cur;

    cur = awal;
    while (cur != NULL)
    {
      cout << cur->ingfo << ", ";
      cur = cur->next;
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