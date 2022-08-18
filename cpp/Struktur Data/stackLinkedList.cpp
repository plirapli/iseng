#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *prev;
  Mhs *next;
} * headNode, *tailNode, *curNode, *newNode, *delNode;

int maks = 5;

// Pengecekan
bool isFull();  // Mengecek apakah data full
bool isEmpty(); // Mengecek apakah data kosong
int count();    // Menghitung jumlah data

// CRUD
void create(string nama, int umur);             // Membuat data (init)
void push(string nama, int umur);               // Tambah data dari bawah
void pop();                                     // Menghapus data dari atas
void peek(int posisi);                          // Mendapatkan index data ke-n
void change(string nama, int umur, int posisi); // Mengganti data ke-n
void destroy();                                 // Menghapus semua data pada array
void readNodes();                               // Menampilkan data

int main()
{
  create("Giantama", 19);
  push("Seva", 17);
  push("Farel", 18);
  push("Syaikul", 20);
  push("Rafli", 22);
  readNodes();
  // Rafli, Syaikul, Farel, Seva, Giantama

  peek(3);
  // Farel

  pop();
  change("Rafli", 21, 2);
  readNodes();
  // Syaikul, Rafli, Seva, Giantama

  destroy();
  readNodes();
  // Data kosong!

  push("Seva", 17);
  readNodes();

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
  headNode->prev = NULL;
  tailNode = headNode;
}

void push(string nama, int umur)
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

      newNode->prev = tailNode; // Prev node baru menunjuk node terakhir
      newNode->next = NULL;     // Next node baru menunjuk NULL
      tailNode->next = newNode; // Next node terakhir menunjuk node baru
      tailNode = newNode;       // Tail pindah ke node baru
    }
  }
}

void pop()
{
  if (isEmpty())
    cout << "Data kosong! \n\n";
  else
  {
    delNode = tailNode;        // Membuat duplikat node terakhir (tail)
    tailNode = tailNode->prev; // Tail pindah ke node sebelumnya (tail->prev)
    tailNode->next = NULL;     // Next node tail menunjuk NULL
    delete delNode;            // Menghapus alamat memori node terakhir
  }
}

void peek(int posisi)
{
  if (isEmpty())
    cout << "Data masih kosong! \n";
  else if (posisi < 1 || posisi > count())
    cout << "Data tidak ditemukan! \n";
  else
  {
    int i = 1;
    curNode = tailNode;
    while (i < posisi)
    {
      curNode = curNode->prev;
      i++;
    }
    cout << posisi << ". "
         << curNode->nama << ", "
         << curNode->umur << "\n\n";
  }
}

void change(string nama, int umur, int posisi)
{
  if (isEmpty())
    cout << "Data masih kosong! \n";
  else if (posisi < 1 || posisi > count())
    cout << "Data tidak ditemukan! \n";
  else
  {
    int i = 1;
    curNode = tailNode;
    while (i < posisi)
    {
      curNode = curNode->prev;
      i++;
    }
    curNode->nama = nama;
    curNode->umur = umur;
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

void readNodes()
{
  cout << "Jumlah data: " << count() << "\n";

  if (isEmpty())
    cout << "Data masih kosong! \n";
  else
  {
    int i = 1;
    curNode = tailNode;
    while (curNode != NULL)
    {
      cout << i << ". " << curNode->nama << ", " << curNode->umur << "\n";

      curNode = curNode->prev;
      i++;
    }
  }
  cout << "\n";
}