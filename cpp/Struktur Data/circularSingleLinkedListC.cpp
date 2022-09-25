#include <iostream>

using namespace std;

typedef int Ingfo;

struct Node
{
  Ingfo ingfo;
  Node *next;
} * head, *tail, *newNode, *delNode;

int jmlNode = 0;

// Cek Node
bool isEmpty() { return head->next == head; }

// Create
void create();                  // Create first node
void sisipNode(Ingfo newIngfo); // Sisip Node

// Delete
void hapusNode(Ingfo ingfoHapus);

// Read
void cetakDepan(); // Print nodes

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

  cout << "\nHapus node 50 \n";
  hapusNode(50);
  cetakDepan();

  cout << "\nHapus node 99 \n";
  hapusNode(99);
  cetakDepan();

  cout << "\nHapus node 5 \n";
  hapusNode(5);
  cetakDepan();

  cout << "\nHapus node 4 \n";
  hapusNode(2);
  cetakDepan();

  sisipNode(13);
  sisipNode(26);
  cetakDepan();

  return 0;
}

void create()
{
  head = new Node();
  head->ingfo = jmlNode; // Ingfo = 0
  head->next = head;     // Node menunjuk diri sendiri (berputar)
}

void sisipNode(Ingfo newIngfo)
{
  Node *newNode, *bantu;

  newNode = new Node;

  newNode->ingfo = newIngfo;
  newNode->next = NULL;

  if (isEmpty()) // Sisip pertama kali
  {
    newNode->next = head; // Next dari node baru nunjuk ke kepala (muter)
    head->next = newNode; // Next dari kepala nunjuk ke node baru
  }
  else if (newIngfo <= head->next->ingfo) // Sisip di depan
  {
    newNode->next = head->next;
    head->next = newNode;
  }
  else
  {
    // Looping sampe posisi - 1
    bantu = head->next;
    while (bantu->next != head && newIngfo > bantu->next->ingfo)
      bantu = bantu->next;

    newNode->next = bantu->next; // Sisip di tengah atau di belakang
    bantu->next = newNode;
  }

  jmlNode++;             // Nambah jumlah node
  head->ingfo = jmlNode; // Jumlah node baru masukkin kepala
}

void hapusNode(Ingfo ingfoHapus)
{
  Node *hapus, *bantu;

  if (isEmpty())
    cout << "List masih kosong";
  else
  {
    // Looping sampai posisi - 1
    bantu = head;
    while (bantu->next != head && ingfoHapus != bantu->next->ingfo)
      bantu = bantu->next;

    if (bantu->next != head)
    {
      hapus = bantu->next;
      bantu->next = bantu->next->next;
      delete hapus;

      jmlNode--;
      head->ingfo = jmlNode;
    }
    else
      cout << "Node tidak ditemukan!\n";
  }
}

void cetakDepan()
{
  cout << "Jumlah data: " << head->ingfo << "\n";

  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    Node *bantu;

    bantu = head->next;
    while (bantu != head)
    {
      cout << bantu->ingfo << ", ";
      bantu = bantu->next;
    }
  }
  cout << "\n";
}
