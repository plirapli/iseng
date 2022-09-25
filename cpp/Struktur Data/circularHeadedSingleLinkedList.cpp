#include <bits/stdc++.h>

using namespace std;

typedef int Ingfo;

struct Node
{
  Ingfo ingfo;
  Node *next;
} * head, *tail;

bool isEmpty() { return head->next == tail; }

void init()
{
  head = new Node;
  tail = new Node;

  head->ingfo = -2147483647;
  head->next = tail;

  tail->ingfo = 2147483647;
  tail->next = head;
}

void sisipNode(Ingfo newIngfo)
{
  Node *newNode, *bantu;

  newNode = new Node;
  newNode->ingfo = newIngfo;

  // Looping sampe posisi - 1
  bantu = head;
  while (newIngfo > bantu->next->ingfo)
    bantu = bantu->next;

  newNode->next = bantu->next; // Sisip di tengah atau di belakang
  bantu->next = newNode;
}

void hapusNode(Ingfo delIngfo)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else
  {
    // Looping sampai posisi - 1
    bantu = head;
    while (bantu->next != tail && delIngfo != bantu->next->ingfo)
      bantu = bantu->next;

    if (delIngfo == bantu->next->ingfo)
    {
      hapus = bantu->next;
      bantu->next = hapus->next;
      delete hapus;
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
    Node *bantu;

    cout << "[" << head->ingfo << "], ";
    // Looping sampe sebelum tail
    bantu = head->next;
    while (bantu != tail)
    {
      cout << bantu->ingfo << ", ";
      bantu = bantu->next;
    }
    cout << "[" << tail->ingfo << "]";
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

    // Cetak
    tail->next = NULL;
    cout << "[" << head->ingfo << "], ";
    bantu = head->next;
    while (bantu != tail)
    {
      cout << bantu->ingfo << ", ";
      bantu = bantu->next;
    }
    cout << "[" << tail->ingfo << "]";
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
  cetakDepan();

  cout << "\nHapus node 50 \n";
  cout << "\nKodisi List setelah di hapus, dibaca dari belakang :\n";
  hapusNode(50);
  cetakMundur();

  return 0;
}