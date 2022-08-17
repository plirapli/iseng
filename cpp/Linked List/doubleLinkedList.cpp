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
// void addLast(string nama, int umur);               // Add node to last
// void addMiddle(string nama, int umur, int posisi); // Add node to nth list

// // Delete
// void delFirst();            // Delete first node
// void delLast();             // Delete last node
// void delMiddle(int posisi); // Delete nth node

// // Update
// void changeFirst(string nama, int umur);              // Change first node
// void changeLast(string nama, int umur);               // Change last node
// void changeMiddle(string nama, int umur, int posisi); // Change nth node

// Read
void readNodes(); // Print nodes
int readLength(); // Return nodes length

int main()
{
  create("Rafli", 21);
  addFirst("Seva", 19);
  // addLast("Farel", 18);
  // delFirst();
  // delLast();
  // addLast("Giantama", 21);

  readNodes();
  // Seva, Rafli

  // changeFirst("Seva", 24);
  // changeLast("Syaikul", 17);
  // addMiddle("Giantama", 18, 2);
  // addFirst("Rafli", 22);
  // delMiddle(3);
  // changeMiddle("Giantomo", 16, 2);

  // printSingleLinkedList();
  // // Rafli, Giantomo, Syaikul

  return 0;
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

void addFirst(string nama, int umur)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  newNode->next = headNode; // Next node baru menunjuk node pertama
  newNode->prev = NULL;     // Prev node baru menunjuk ke NULL
  headNode->prev = newNode; // Prev node pertama menunjuk ke node baru
  headNode = newNode;       // Head pindah ke node baru
}

// void addMiddle(string nama, int umur, int posisi)
// {
//   if (posisi < 1 || posisi > readLength())
//     cout << "Posisi invalid! \n";
//   else if (posisi == 1)
//     cout << "Posisi bukan di tengah! \n";
//   else
//   {
//     newNode = new Mhs();
//     newNode->nama = nama;
//     newNode->umur = umur;

//     // Traversing
//     curNode = headNode;
//     int i = 1;
//     while (i < posisi - 1)
//     {
//       curNode = curNode->next;
//       i++;
//     }

//     newNode->next = curNode->next;
//     curNode->next = newNode;
//   }
// }

// void addLast(string nama, int umur)
// {
//   newNode = new Mhs();
//   newNode->nama = nama;
//   newNode->umur = umur;

//   newNode->next = NULL;
//   tailNode->next = newNode;
//   tailNode = newNode;
// }

// void changeFirst(string nama, int umur)
// {
//   headNode->nama = nama;
//   headNode->umur = umur;
// }

// void changeMiddle(string nama, int umur, int posisi)
// {
//   if (posisi < 1 || posisi > readLength())
//     cout << "Posisi invalid! \n";
//   else if (posisi == 1 || posisi == readLength())
//     cout << "Posisi bukan di tengah! \n";
//   else
//   {
//     curNode = headNode;
//     int i = 1;
//     while (i < posisi)
//     {
//       curNode = curNode->next;
//       i++;
//     }

//     curNode->nama = nama;
//     curNode->umur = umur;
//   }
// }

// void changeLast(string nama, int umur)
// {
//   tailNode->nama = nama;
//   tailNode->umur = umur;
// }

// void delFirst()
// {
//   delNode = headNode;
//   headNode = headNode->next;
//   delete delNode;
// }

// void delMiddle(int posisi)
// {
//   if (posisi < 1 || posisi > readLength())
//     cout << "Posisi invalid! \n";
//   else if (posisi == 1 || posisi == readLength())
//     cout << "Posisi bukan di tengah! \n";
//   else
//   {
//     Mhs *before;

//     curNode = headNode;
//     int i = 1;
//     while (i <= posisi)
//     {
//       if (i == posisi - 1)
//         before = curNode;
//       if (i == posisi)
//         delNode = curNode;

//       curNode = curNode->next;
//       i++;
//     }

//     before->next = curNode;
//     delete delNode;
//   }
// }

// void delLast()
// {
//   delNode = tailNode;

//   // Traversing
//   curNode = headNode;
//   while (curNode->next != tailNode)
//     curNode = curNode->next;

//   tailNode = curNode;
//   tailNode->next = NULL;
//   delete delNode;
// }

void readNodes()
{
  cout << "Jumlah data: " << readLength() << "\n";

  curNode = headNode;
  int i = 1;
  while (curNode != NULL)
  {
    cout << i << ". " << curNode->nama << ", " << curNode->umur << "\n";

    curNode = curNode->next;
    i++;
  }
  cout << "\n";
}

int readLength()
{
  curNode = headNode;
  int i = 0;
  while (curNode != NULL)
  {
    curNode = curNode->next;
    i++;
  }

  return i;
}
