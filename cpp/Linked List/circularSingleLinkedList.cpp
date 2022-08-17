#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *next;
} * head, *tail, *cur, *newNode, *delNode;

// Create
void create(string nama, int umur); // Create first node
// void addFirst(string nama, int umur); // Add node to first
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
void print();     // Print nodes
int readLength(); // Return nodes length

int main()
{
  create("Rafli", 21);
  // addFirst("Seva", 19);
  // addLast("Farel", 18);
  // delFirst();
  // delLast();
  // addLast("Giantama", 21);

  print();
  // Rafli

  // changeFirst("Seva", 24);
  // changeLast("Syaikul", 17);
  // addMiddle("Giantama", 18, 2);
  // addFirst("Rafli", 22);
  // delMiddle(3);
  // changeMiddle("Giantomo", 16, 2);

  // print();
  // // Rafli, Giantomo, Syaikul

  return 0;
}

void create(string nama, int umur)
{
  head = new Mhs();

  head->nama = nama;
  head->umur = umur;

  tail = head;
  tail->next = head;
}

// void addFirst(string nama, int umur)
// {
//   if (head == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     newNode = new Mhs();
//     newNode->nama = nama;
//     newNode->umur = umur;

//     newNode->next = head;
//     head = newNode;
//   }
// }

// void addLast(string nama, int umur)
// {
//   if (head == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     newNode = new Mhs();
//     newNode->nama = nama;
//     newNode->umur = umur;

//     newNode->next = NULL;
//     tail->next = newNode;
//     tail = newNode;
//   }
// }

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
//     cur = head;
//     int i = 1;
//     while (i < posisi - 1)
//     {
//       cur = cur->next;
//       i++;
//     }

//     newNode->next = cur->next;
//     cur->next = newNode;
//   }
// }

// void changeFirst(string nama, int umur)
// {
//   head->nama = nama;
//   head->umur = umur;
// }

// void changeMiddle(string nama, int umur, int posisi)
// {
//   if (posisi < 1 || posisi > readLength())
//     cout << "Posisi invalid! \n";
//   else if (posisi == 1 || posisi == readLength())
//     cout << "Posisi bukan di tengah! \n";
//   else
//   {
//     // Melakukan traversing sampai i < posisi
//     cur = head;
//     int i = 1;
//     while (i < posisi)
//     {
//       cur = cur->next;
//       i++;
//     }

//     cur->nama = nama;
//     cur->umur = umur;
//   }
// }

// void changeLast(string nama, int umur)
// {
//   tail->nama = nama;
//   tail->umur = umur;
// }

// void delFirst()
// {
//   if (head == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     delNode = head;
//     head = head->next;
//     delete delNode;
//   }
// }

// void delLast()
// {
//   if (head == NULL)
//     cout << "Linked List belum dibuat! \n";
//   else
//   {
//     delNode = tail;

//     // Traversing
//     cur = head;
//     while (cur->next != tail)
//       cur = cur->next;

//     tail = cur;
//     tail->next = NULL;
//     delete delNode;
//   }
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

void print()
{
  cout << "Jumlah data: " << readLength() << "\n";

  if (head == NULL)
    cout << "Data masih kosong! \n";
  else
  {
    cur = head;
    int i = 1;
    while (cur->next != head)
    {
      cout << i << ". " << cur->nama << ", " << cur->umur << "\n";

      cur = cur->next;
      i++;
    }
    cout << i << ". " << cur->nama << ", " << cur->umur << "\n";
  }
  cout << "\n";
}

int readLength()
{
  cur = head;
  int i = 0;
  while (cur->next != head)
  {
    cur = cur->next;
    i++;
  }
  i++;

  return i;
}
