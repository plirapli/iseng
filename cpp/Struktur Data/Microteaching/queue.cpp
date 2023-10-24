#include <iostream>

using namespace std;

struct QueueNode
{
  int info;
  QueueNode *next;
} *nodeDepan, *nodeBelakang, *curNode, *newNode, *delNode;

// CRUD
void create(int infoBaru);  // Membuat data (init)
void enqueue(int infoBaru); // Tambah data dari bawah
void dequeue();             // Menghapus data dari atas
void display();             // Menampilkan data

int main()
{
  enqueue(19);
  enqueue(20);
  enqueue(22);
  display(); // 19, 20, 22
  dequeue();
  display(); // 20, 22
  enqueue(17);
  display(); // 17, 20, 22
  return 0;
}

void create(int infoBaru)
{
  nodeDepan = new QueueNode();
  nodeDepan->info = infoBaru;

  nodeDepan->next = NULL;
  nodeBelakang = nodeDepan;
}

void enqueue(int infoBaru)
{
  if (nodeDepan == NULL)
    create(infoBaru);
  else
  {
    newNode = new QueueNode();
    newNode->info = infoBaru;

    newNode->next = NULL;         // Next node baru menunjuk NULL
    nodeBelakang->next = newNode; // Next node terakhir menunjuk node baru
    nodeBelakang = newNode;       // Tail pindah ke node baru
  }
}

void dequeue()
{
  delNode = nodeDepan;         // Membuat duplikat node terakhir (tail)
  nodeDepan = nodeDepan->next; // Head pindah ke next node (tail->prev)
  delete delNode;              // Menghapus alamat memori node terakhir
}

void display()
{
  curNode = nodeDepan;
  cout << "---- Antrian Depan ---- \n";
  while (curNode != NULL)
  {
    cout << curNode->info << "\n";
    curNode = curNode->next;
  }
  cout << "\n";
}