#include <iostream>
using namespace std;

struct Node
{
  int info;
  Node *next;
} *kepala, *ekor;

void create()
{
  kepala = new Node;
  ekor = new Node;

  kepala->info = -2147483647;
  ekor->info = 2147483647;
  kepala->next = ekor;
}

void sisipNode(int infoBaru)
{
  Node *nodeBaru, *bantu;

  // Bikin node baru
  nodeBaru = new Node;
  nodeBaru->info = infoBaru;

  // Looping sampe posisi - 1
  bantu = kepala;
  while (infoBaru > bantu->next->info)
    bantu = bantu->next;

  nodeBaru->next = bantu->next; // Sisip
  bantu->next = nodeBaru;
}

void cetak()
{
  Node *depan, *bantu;

  // Looping sampe sebelum node terakhir
  bantu = kepala->next;
  while (bantu != ekor)
  {
    cout << bantu->info << "\n";
    bantu = bantu->next;
  }
  cout << "\n";
}

int main()
{
  create();

  sisipNode(5);
  sisipNode(9);
  sisipNode(12);
  sisipNode(4);

  cetak();
}