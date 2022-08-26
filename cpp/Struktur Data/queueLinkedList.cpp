#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *next;
} * headNode, *tailNode, *curNode, *newNode, *delNode;

int maks = 5;

// Pengecekan
bool isFull();  // Mengecek apakah data full
bool isEmpty(); // Mengecek apakah data kosong
int count();    // Menghitung jumlah data

// CRUD
void create(string nama, int umur);  // Membuat data (init)
void enqueue(string nama, int umur); // Tambah data dari bawah
void dequeue();                      // Menghapus data dari atas
void destroy();                      // Menghapus semua data pada array
void display();                      // Menampilkan data

int main()
{
  enqueue("Giantama", 19);
  enqueue("Syaikul", 20);
  enqueue("Rafli", 22);
  display();
  // Giantama, Syaikul, Rafli

  dequeue();
  display();
  // Syaikul, Rafli

  destroy();
  display();
  // Data kosong!

  enqueue("Seva", 17);
  display();
  // Seva

  return 0;
}

bool isFull()
{
  return count() == maks;
}

bool isEmpty()
{
  return count() == 0;
}

int count()
{
  int i = 0;
  curNode = headNode;
  while (curNode != NULL)
  {
    curNode = curNode->next;
    i++;
  }
  return i;
}

void create(string nama, int umur)
{
  headNode = new Mhs();
  headNode->nama = nama;
  headNode->umur = umur;

  headNode->next = NULL;
  tailNode = headNode;
}

void enqueue(string nama, int umur)
{
  if (isFull())
    cout << "Data Full! \n\n";
  else
  {
    if (isEmpty())
      create(nama, umur);
    else
    {
      newNode = new Mhs();
      newNode->nama = nama;
      newNode->umur = umur;

      newNode->next = NULL;     // Next node baru menunjuk NULL
      tailNode->next = newNode; // Next node terakhir menunjuk node baru
      tailNode = newNode;       // Tail pindah ke node baru
    }
  }
}

void dequeue()
{
  if (isEmpty())
    cout << "Data kosong! \n\n";
  else
  {
    delNode = headNode;        // Membuat duplikat node terakhir (tail)
    headNode = headNode->next; // Head pindah ke next node (tail->prev)
    delete delNode;            // Menghapus alamat memori node terakhir
  }
}

void destroy()
{
  curNode = headNode;
  while (curNode != NULL)
  {
    delNode = curNode;
    curNode = curNode->next;
    delete delNode;
  }
  headNode = NULL;
  tailNode = NULL;
}

void display()
{
  cout << "Jumlah data: " << count() << "\n";

  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    int i = 1;
    curNode = headNode;
    while (i <= maks)
    {
      if (curNode != NULL)
      {
        cout << i << ". " << curNode->nama << ", " << curNode->umur << "\n";
        curNode = curNode->next;
      }
      else
        cout << i + 1 << ". [Kosong] \n";

      i++;
    }
  }
  cout << "\n";
}