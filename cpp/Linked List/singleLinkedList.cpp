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
void delFirst(); // Delete first node
void delLast();  // Delete last node

// Update
void changeFirst(string nama, int umur); // Change first node
void changeLast(string nama, int umur);  // Change last node

// Read
void printSingleLinkedList(); // Print nodes

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

  printSingleLinkedList();
  // Seva, Giantama, Syaikul

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

  // Tranversing
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