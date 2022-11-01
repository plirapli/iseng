#include <iostream>
#include <malloc.h>

using namespace std;

const int maxArr = 50;

struct typequeue
{
  int belakang;
  int elemen[maxArr];
};
struct typequeue queue;

void buat();
void cetak();
void enqueue(int IB);
void dequeue();

// Cek kondisi queue
bool isEmpty() { return queue.belakang == 0; }
bool isFull() { return queue.belakang == maxArr; }

int main()
{
  buat();
  enqueue(12);
  enqueue(78);
  enqueue(5);
  enqueue(34);
  cetak();
  cout << "\n\n";

  dequeue();
  cetak();
  cout << "\n\n";

  dequeue();
  cetak();
  cout << "\n\n";

  enqueue(89);
  cetak();
}

void buat()
{
  queue.belakang = 0;
}

void enqueue(int IB)
{
  if (isFull())
    cout << "Queue Overflow! \n";
  else
  {
    queue.belakang++;
    queue.elemen[queue.belakang] = IB;
  }
}

void dequeue()
{
  if (isEmpty())
    cout << "Queue Underflow! \n";
  else
  {
    int ID, i;

    ID = queue.elemen[1];
    for (i = 1; i < queue.belakang; i++)
      queue.elemen[i] = queue.elemen[i + 1];
    queue.belakang--;
  }
}

void cetak()
{
  int i = 1;
  while (i <= queue.belakang)
  {
    cout << " " << queue.elemen[i];
    i++;
  }
}
