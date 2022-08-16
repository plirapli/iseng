#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *next;
} * head, *tail, *cur, *newNode, *delNode;

void createSingleLinkedList(string nama, int umur); // Create first node

// Create
void addFirst(string nama, int umur);              // Add node to first
void addMiddle(string nama, int umur, int posisi); // Add node to nth list
void addLast(string nama, int umur);               // Add node to last

// Delete
void delFirst();            // Delete first node
void delMiddle(int posisi); // Delete nth node
void delLast();             // Delete last node

// Update
void changeFirst(string nama, int umur); // Change first node
void changeLast(string nama, int umur);  // Change last node

// Read
void printSingleLinkedList(); // Print nodes
int readLength();             // Return nodes length

int main()
{
  createSingleLinkedList("Rafli", 21);
  addFirst("Seva", 19);
  addLast("Farel", 18);
  delFirst();
  delLast();
  addLast("Giantama", 21);

  printSingleLinkedList();
  // Rafli, Giantama

  changeFirst("Seva", 24);
  changeLast("Syaikul", 17);
  addMiddle("Giantama", 18, 2);
  addFirst("Rafli", 22);
  delMiddle(3);

  printSingleLinkedList();
  // Rafli, Seva, Syaikul

  return 0;
}

void createSingleLinkedList(string nama, int umur)
{
  head = new Mhs();
  head->nama = nama;
  head->umur = umur;

  head->next = NULL;
  tail = head;
}

void addFirst(string nama, int umur)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  newNode->next = head;
  head = newNode;
}

void addMiddle(string nama, int umur, int posisi)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  // Traversing
  cur = head;
  int i = 1;
  while (i < posisi - 1)
  {
    cur = cur->next;
    i++;
  }

  newNode->next = cur->next;
  cur->next = newNode;
}

void addLast(string nama, int umur)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void changeFirst(string nama, int umur)
{
  head->nama = nama;
  head->umur = umur;
}

void changeLast(string nama, int umur)
{
  tail->nama = nama;
  tail->umur = umur;
}

void delFirst()
{
  delNode = head;
  head = head->next;
  delete delNode;
}

void delMiddle(int posisi)
{
  if (posisi < 1 || posisi > readLength())
    cout << "Posisi invalid! \n";
  else if (posisi == 1 || posisi == readLength())
    cout << "Posisi bukan di tengah! \n";
  else
  {
    Mhs *before;

    cur = head;
    int i = 1;
    while (i <= posisi)
    {
      if (i == posisi - 1)
        before = cur;
      if (i == posisi)
        delNode = cur;

      cur = cur->next;
      i++;
    }

    before->next = cur;
    delete delNode;
  }
}

void delLast()
{
  delNode = tail;

  // Traversing
  cur = head;
  while (cur->next != tail)
    cur = cur->next;

  tail = cur;
  tail->next = NULL;
  delete delNode;
}

void printSingleLinkedList()
{
  cout << "Jumlah data: " << readLength() << "\n";

  cur = head;
  int i = 1;
  while (cur != NULL)
  {
    cout << i << ". " << cur->nama << ", " << cur->umur << "\n";

    cur = cur->next;
    i++;
  }
  cout << "\n";
}

int readLength()
{
  cur = head;
  int i = 0;
  while (cur != NULL)
  {
    cur = cur->next;
    i++;
  }

  return i;
}
