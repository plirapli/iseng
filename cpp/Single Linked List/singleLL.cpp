#include <iostream>

using namespace std;

struct Mhs
{
  string nama;
  int umur;

  Mhs *next;
} * head, *tail, *cur, *newNode;

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
};

void addLast(string nama, int umur)
{
  newNode = new Mhs();
  newNode->nama = nama;
  newNode->umur = umur;

  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
};

void printSingleLinkedList()
{
  cur = head;

  while (cur != NULL)
  {
    cout << "Nama: " << cur->nama << "\n";
    cout << "Tgl Lahir: " << cur->umur << "\n\n";

    cur = cur->next;
  }
}

int main()
{
  createSingleLinkedList("Rafli", 21);
  addFirst("Seva", 19);
  addLast("Farel", 18);

  printSingleLinkedList();

  return 0;
}