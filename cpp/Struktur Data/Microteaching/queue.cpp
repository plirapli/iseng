#include <iostream>

using namespace std;

struct QueueNode
{
  int info;
  QueueNode *next;
} *headNode, *tailNode, *curNode, *newNode, *delNode;

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
  headNode = new QueueNode();
  headNode->info = infoBaru;

  headNode->next = NULL;
  tailNode = headNode;
}

void enqueue(int infoBaru)
{
  if (headNode == NULL)
    create(infoBaru);
  else
  {
    newNode = new QueueNode();
    newNode->info = infoBaru;

    newNode->next = NULL;     // Next node baru menunjuk NULL
    tailNode->next = newNode; // Next node terakhir menunjuk node baru
    tailNode = newNode;       // Tail pindah ke node baru
  }
}

void dequeue()
{
  delNode = headNode;        // Membuat duplikat node terakhir (tail)
  headNode = headNode->next; // Head pindah ke next node (tail->prev)
  delete delNode;            // Menghapus alamat memori node terakhir
}

void display()
{
  int i = 1;
  curNode = headNode;
  cout << "---- Antrian Depan ---- \n";
  while (curNode != NULL)
  {
    cout << curNode->info << "\n";
    curNode = curNode->next;
  }
  cout << "\n";
}