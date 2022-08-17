#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *prev;
  Mhs *next;
} * headNode, *tailNode, *curNode, *newNode, *delNode;

// Create
void create(string nama, int umur);   // Create first node
void addFirst(string nama, int umur); // Add node to first
void addLast(string nama, int umur);  // Add node to last
// void addMiddle(string nama, int umur, int posisi); // Add node to nth list

// // Delete
// void delFirst();            // Delete first node
// void delLast();             // Delete last node
// void delMiddle(int posisi); // Delete nth node

// Update
void changeFirst(string nama, int umur);              // Change first node
void changeLast(string nama, int umur);               // Change last node
void changeMiddle(string nama, int umur, int posisi); // Change nth node

// Read
void readNodes(); // Print nodes
int readLength(); // Return nodes length

int main()
{
  create("Rafli", 21);
  addFirst("Seva", 19);
  addLast("Farel", 18);
  // delFirst();
  // delLast();
  // addLast("Giantama", 21);

  readNodes();
  // Rafli, Seva, Farel

  // changeFirst("Seva", 24);
  // changeLast("Syaikul", 17);
  // addMiddle("Giantama", 18, 2);
  // addFirst("Rafli", 22);
  // delMiddle(3);
  // changeMiddle("Giantomo", 16, 2);

  // readNodes();
  // // Rafli, Giantomo, Syaikul

  return 0;
}

void create(string nama, int umur)
{
  headNode = new Mhs();
  headNode->nama = nama;
  headNode->umur = umur;

  headNode->prev = headNode;
  headNode->next = headNode;
  tailNode = headNode;
}

void addFirst(string nama, int umur)
{
  if (headNode == NULL)
    cout << "Linked List belum dibuat! \n";
  else
  {
    // Membuat node baru
    newNode = new Mhs();
    newNode->nama = nama;
    newNode->umur = umur;

    newNode->prev = tailNode; // Prev node baru menunjuk tail
    newNode->next = headNode; // Next node baru menunjuk node pertama (head)
    headNode->prev = newNode; // Prev node pertama menunjuk node baru
    tailNode->next = newNode; // Next tail menunjuk ke node baru
    headNode = newNode;       // Head pindah ke node baru
  }
}

void addLast(string nama, int umur)
{
  if (headNode == NULL)
    cout << "Linked List belum dibuat! \n";
  else
  {
    // Membuat node baru
    newNode = new Mhs();
    newNode->nama = nama;
    newNode->umur = umur;

    newNode->prev = tailNode; // Prev node baru menunjuk node terakhir
    newNode->next = headNode; // Next node baru menunjuk head
    tailNode->next = newNode; // Next node terakhir menunjuk node baru
    headNode->prev = newNode; // Prev head menunjuk ke node baru
    tailNode = newNode;       // Tail pindah ke node baru
  }
}

// void addMiddle(string nama, int umur, int posisi)
// {
//   if (headNode == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     if (posisi < 1 || posisi > readLength() + 1)
//       cout << "Posisi invalid! \n";
//     else if (posisi == 1 || posisi == readLength() + 1)
//       cout << "Posisi bukan di tengah! \n";
//     else
//     {
//       // Membuat node baru untuk menyimpan node posisi ke-n tambah 1
//       Mhs *afterNode;

//       // Membuat node baru
//       newNode = new Mhs();
//       newNode->nama = nama;
//       newNode->umur = umur;

//       // Traversing sampai node posisi ke-n kurang 1.
//       curNode = headNode;
//       int i = 1;
//       while (i < posisi - 1)
//       {
//         curNode = curNode->next;
//         i++;
//       }

//       afterNode = curNode->next; // Node after menunjuk ke next node current
//       afterNode->prev = newNode; // Prev node after menunjuk ke node baru
//       newNode->prev = curNode;   // Prev node baru menunjuk ke node current
//       newNode->next = afterNode; // Next node baru menunjuk ke node after
//       curNode->next = newNode;   // Next node current menunjuk ke node baru
//     }
//   }
// }

// void delFirst()
// {
//   if (headNode == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     delNode = headNode;        // Membuat duplikat node head
//     headNode = headNode->next; // Head pindah ke node kedua (head->next)
//     headNode->prev = NULL;     // Prev node head menunjuk NULL
//     delete delNode;            // Menghapus alamat memori node pertama
//   }
// }

// void delLast()
// {
//   if (headNode == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     delNode = tailNode;        // Membuat duplikat node terakhir (tail)
//     tailNode = tailNode->prev; // Tail pindah ke node sebelumnya (tail->prev)
//     tailNode->next = NULL;     // Next node tail menunjuk NULL
//     delete delNode;            // Menghapus alamat memori node terakhir
//   }
// }

// void delMiddle(int posisi)
// {
//   if (headNode == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     if (posisi < 1 || posisi > readLength())
//       cout << "Posisi invalid! \n";
//     else if (posisi == 1 || posisi == readLength())
//       cout << "Posisi bukan di tengah! \n";
//     else
//     {
//       // Membuat variabel baru untuk menyimpan node posisi ke-n tambah 1
//       Mhs *afterNode;

//       // Traversing sampai posisi ke-n kurang 1
//       curNode = headNode;
//       int i = 1;
//       while (i < posisi - 1)
//       {
//         curNode = curNode->next;
//         i++;
//       }

//       delNode = curNode->next;   // Node delete merupakan next dari node current
//       afterNode = delNode->next; // Node after merupakan next dari node delete
//       afterNode->prev = curNode; // Ubah prev node after menjadi nunjuk ke current
//       curNode->next = afterNode; // Ubah next node current menjadi nunjuk ke node after

//       delete delNode; // Hapus node posisi ke-n
//     }
//   }
// }

void changeFirst(string nama, int umur)
{
  headNode->nama = nama;
  headNode->umur = umur;
}

void changeLast(string nama, int umur)
{
  tailNode->nama = nama;
  tailNode->umur = umur;
}

void changeMiddle(string nama, int umur, int posisi)
{
  if (posisi < 1 || posisi > readLength())
    cout << "Posisi invalid! \n";
  else if (posisi == 1 || posisi == readLength())
    cout << "Posisi bukan di tengah! \n";
  else
  {
    curNode = headNode;
    int i = 1;
    while (i < posisi)
    {
      curNode = curNode->next;
      i++;
    }

    curNode->nama = nama;
    curNode->umur = umur;
  }
}

void readNodes()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (headNode == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    curNode = headNode;
    int i = 1;
    while (curNode->next != headNode)
    {
      cout << i << ". " << curNode->nama << ", " << curNode->umur << "\n";

      curNode = curNode->next;
      i++;
    }
    cout << i << ". " << curNode->nama << ", " << curNode->umur << "\n";
  }
  cout << "\n";
}

int readLength()
{
  curNode = headNode;
  int i = 0;
  while (curNode->next != headNode)
  {
    curNode = curNode->next;
    i++;
  }
  i++;

  return i;
}
