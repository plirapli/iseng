#include <stdio.h>
#include <malloc.h>
using namespace std;

typedef int Ingfo;
typedef struct typenode *typeptr;

struct typenode
{
  Ingfo info;
  typeptr next;
};
typeptr kepala;

int jmlNode = 0;

void create()
{
  kepala = (typenode *)malloc(sizeof(typenode));
  kepala->info = jmlNode; // Ingo = 0
  kepala->next = kepala;  // Node menunjuk diri sendiri (berputar)
}

bool isKosong() { return kepala->next == kepala; };

void sisipNode(Ingfo newIngfo)
{
  typeptr newNode, bantu;

  newNode = (typenode *)malloc(sizeof(typenode));
  newNode->info = newIngfo;

  if (isKosong())
  {
    newNode->next = kepala;
    kepala->next = newNode;
  }
  else
  {
    // Looping sampe posisi - 1
    bantu = kepala;
    while (newIngfo < bantu->next->info && bantu->next != kepala)
      bantu = bantu->next;

    // Sisip tengah & belakang
    newNode->next = bantu->next;
    bantu->next = newNode;
  }

  jmlNode++;
  kepala->info = jmlNode;
}

void cetakMundur()
{
  typeptr depan, belakang, bantu;

  depan = kepala;
  bantu = kepala;
  while (bantu->next != kepala)
    bantu = bantu->next;
  kepala = bantu;
  belakang = kepala;

  // Muter arah
  do
  {
    bantu = depan;
    while (bantu->next != belakang)
      bantu = bantu->next;

    belakang->next = bantu;
    belakang = bantu;
  } while (belakang != depan);
  belakang->next = kepala;

  // Cetak
  bantu = kepala;
  while (bantu != belakang && bantu->info < 150)
  {
    printf("%d ", bantu->info);
    bantu = bantu->next;
  }
}

int main()
{
  create();
  sisipNode(200);
  sisipNode(160);
  sisipNode(140);
  sisipNode(120);
  sisipNode(100);
  cetakMundur();

  return 0;
}