/* Implementasi queue menggunakan list */
#include <iostream>

using namespace std;

typedef char typeinfo;
struct typequeue
{
  typeinfo info;
  typequeue *next;
} * antrianDepan, *antrianBelakang;

void buat();
void enqueue(typeinfo *IB);
void dequeue();
void cetak();

// Cek kondisi antrian
bool isEmpty() { return antrianDepan == NULL; }

int main()
{
  buat();

  cout << "Kondisi Awal queue setelah di enqueue : \n";
  enqueue("A");
  enqueue("B");
  enqueue("S");
  enqueue("D");
  cetak();

  cout << "\n\nKondisi queue setelah di dequeue : \n";
  dequeue();
  cetak();

  cout << "\n\nKondisi Akhir queue setelah di enqueue : \n";
  enqueue("E");
  enqueue("F");
  cetak();
}

void buat()
{
  antrianDepan = new typequeue;
  antrianDepan = NULL;
  antrianBelakang = antrianDepan;
}

void enqueue(typeinfo *IB)
{
  typequeue *NB;

  NB = new typequeue;
  NB->info = *IB;

  if (antrianDepan == NULL)
    antrianDepan = NB;
  else
    antrianBelakang->next = NB;

  antrianBelakang = NB;
  antrianBelakang->next = NULL;
}

void dequeue()
{
  typequeue *hapus;

  if (isEmpty())
    cout << "Queue masih kosong !";
  else
  {
    hapus = antrianDepan;
    antrianDepan = hapus->next;
    free(hapus);
  }
}

void cetak()
{
  typequeue *bantu;

  bantu = antrianDepan;
  do
  {
    cout << " " << bantu->info;
    cout << " ";
    bantu = bantu->next;
  } while (bantu != NULL);
}