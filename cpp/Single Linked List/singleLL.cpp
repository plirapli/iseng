#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *next;
} * head, *tail, *cur, *newNode, *delNode;
;

void createSingleLinkedList(string nama, int umur); // Create first node
void addFirst(string nama, int umur);               // Add node to first
void addLast(string nama, int umur);                // Add node to last
void delFirst();                                    // Delete first node
void delLast();                                     // Delete last node
void printSingleLinkedList();                       // Print nodes

int main()
{
  createSingleLinkedList("Rafli", 21);
  addFirst("Seva", 19);
  addLast("Farel", 18);

  delFirst();

  printSingleLinkedList();

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

void addLast(string nama, int umur)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void delFirst()
{
  delNode = head;
  head = head->next;
  delete delNode;
}

void printSingleLinkedList()
{
  cur = head;
  int i = 1;

  while (cur != NULL)
  {
    cout << i << ". "
         << "Nama: " << cur->nama << ", "
         << cur->umur << "\n";

    cur = cur->next;
    i++;
  }
  cout << "\n";
}