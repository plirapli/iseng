#include <iostream>

using namespace std;

struct Ingfo
{
  string nama;
  int umur;
};

struct Node
{
  Ingfo ingfo;
  Node *next;
} * awal, *akhir;

void init(); // Initiate node

// Create
void addFirst(Ingfo newIngfo);              // Add node to first
void addLast(Ingfo newIngfo);               // Add node to last
void addMiddle(Ingfo newIngfo, int posisi); // Add node to nth list

// Delete
void delFirst();            // Delete first node
void delLast();             // Delete last node
void delMiddle(int posisi); // Delete nth node

// Read
void printSingleLinkedList(); // Print nodes
int readLength();             // Return nodes length

int main()
{
  Ingfo temp;

  temp.nama = "Seva";
  temp.umur = 19;
  addFirst(temp);

  temp.nama = "Farel";
  temp.umur = 18;
  addLast(temp);

  delFirst();

  temp.nama = "Syaikul";
  temp.umur = 18;
  addFirst(temp);

  delLast();

  temp.nama = "Giantama";
  temp.umur = 21;
  addLast(temp);

  printSingleLinkedList();
  // Syaikul, Giantama

  // addMiddle("Giantama", 18, 2);
  // addFirst("Rafli", 22);
  // delMiddle(3);

  // printSingleLinkedList();
  // Rafli, Giantomo, Syaikul

  return 0;
}

void init()
{
  awal = NULL;
  akhir = NULL;
}

void addFirst(Ingfo newIngfo)
{
  if (awal == NULL)
    init();

  Node *newNode;
  newNode = new Node();

  newNode->ingfo = newIngfo; // Masukkin data
  newNode->next = awal;      // Next dari node baru menunjuk ke awal
  awal = newNode;            // Awal pindah ke node baru

  if (akhir == NULL)
    akhir = newNode;
}

void addLast(Ingfo newIngfo)
{
  if (awal == NULL)
    init();
  else
  {
    Node *newNode;
    newNode = new Node();

    newNode->ingfo = newIngfo; // Masukkin data
    newNode->next = NULL;      // Next dari node baru NULL
    akhir->next = newNode;     // Next dari akhir menunjuk ke node baru
    akhir = newNode;           // Akhir pindah ke node baru
  }
}

void addMiddle(Ingfo newIngfo, int posisi)
{
  if (posisi < 1 || posisi > readLength())
    cout << "Posisi invalid! \n";
  else if (posisi == 1)
    cout << "Posisi bukan di tengah! \n";
  else
  {
    Node *newNode;
    newNode = new Node();

    newNode->ingfo = newIngfo; // Masukkin data

    // Traversing
    Node *cur;
    cur = awal;
    int i = 1;
    while (i < posisi - 1)
    {
      cur = cur->next;
      i++;
    }

    newNode->next = cur->next;
    cur->next = newNode;
  }
}

void delFirst()
{
  if (awal == NULL)
    cout << "Linked List belum dibuat! \n";
  else
  {
    Node *delNode;

    delNode = awal;
    awal = awal->next;
    delete delNode;
  }
}

void delLast()
{
  if (awal == NULL)
    cout << "Linked List belum dibuat! \n";
  else
  {
    Node *delNode, *cur;

    delNode = akhir;

    // Traversing
    cur = awal;
    while (cur->next != akhir)
      cur = cur->next;

    akhir = cur;
    akhir->next = NULL;
    delete delNode;
  }
}

// void delMiddle(int posisi)
// {
//   if (posisi < 1 || posisi > readLength())
//     cout << "Posisi invalid! \n";
//   else if (posisi == 1 || posisi == readLength())
//     cout << "Posisi bukan di tengah! \n";
//   else
//   {
//     Mhs *before;

//     cur = head;
//     int i = 1;
//     while (i <= posisi)
//     {
//       if (i == posisi - 1)
//         before = cur;
//       if (i == posisi)
//         delNode = cur;

//       cur = cur->next;
//       i++;
//     }

//     before->next = cur;
//     delete delNode;
//   }
// }

void printSingleLinkedList()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (awal == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    Node *cur;
    int i = 1;

    cur = awal;
    while (cur != NULL)
    {
      cout << i << ". " << cur->ingfo.nama << ", " << cur->ingfo.umur << "\n";
      cur = cur->next;
      i++;
    }
  }
  cout << "\n";
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
