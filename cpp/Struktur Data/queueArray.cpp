/*
  Sifat Queue:
  - FIFO
  - Seperti antrian, dimulai dari depan -> belakang
*/

#include <iostream>

using namespace std;

int back = 0, front = 0, maks = 5;
string arrMhs[5];

void enqueue(string data); // Tambah data dari bawah
void dequeue();            // Menghapus data dari atas
bool isFull();             // Mengecek apakah data full
bool isEmpty();            // Mengecek apakah data kosong
int count();               // Menghitung jml data
void display();            // Menampilkan data
void destroy();            // Menghapus semua data pada array

int main()
{
  enqueue("Seva");
  enqueue("Syaikul");
  display();
  // Seva, Syaikul

  enqueue("Rafli");
  dequeue();
  display();
  // Syaikul, Rafli

  destroy();
  display();
  // Data kosong!

  return 0;
}

bool isFull()
{
  return back == maks;
}

bool isEmpty()
{
  return front == 0;
}

void enqueue(string data)
{
  if (isFull())
    cout << "Data full! \n\n";
  else
  {
    arrMhs[back] = data;
    back++;

    // Pengecekan apakah array kosong atau tidak
    front = isEmpty() ? front + 1 : front + 0;
  }
}

void dequeue()
{
  if (isEmpty())
    cout << "Data kosong! \n\n";
  else
  {
    for (int i = 0; i < back; i++)
      arrMhs[i] = arrMhs[i + 1];

    arrMhs[back - 1] = "";
    back--;

    // Pengecekan apakah array kosong setelah dihapus atau tidak
    front = (back == 0) ? front - 1 : front - 0;
  }
}

int countArr()
{
  return back;
}

void display()
{
  cout << "Jumlah data terisi: " << countArr() << "\n";
  cout << "Data array: \n";
  for (int i = 0; i < maks; i++)
  {
    if (arrMhs[i] != "")
      cout << i + 1 << ". " << arrMhs[i] << "\n";

    else
      cout << i + 1 << ". [Kosong] \n";
  }

  cout << "\n";
}

void destroy()
{
  for (int i = 0; i < maks; i++)
    arrMhs[i] = "";

  back = 0;
  front = 0;
}