#include <iostream>

using namespace std;

int maks = 5;
int top = 0;
string arrMhs[5];

bool isFull();                              // Mengecek apakah data full
bool isEmpty();                             // Mengecek apakah data kosong
void pushArr(string data);                  // Tambah data dari bawah
void popArr();                              // Menghapus data dari atas
int peekArr(int posisi);                    // Mendapatkan index data ke-n
int countArr();                             // Menghitung jml data
void changeArr(string newData, int posisi); // Mengganti data ke-n
void destroyArr();                          // Menghapus semua data pada array
void displayArr();                          // Menampilkan data

int main()
{
  pushArr("Seva");
  pushArr("Giantama");
  pushArr("Farel");
  pushArr("Syaikul");
  displayArr();
  // Syaikul, Farel, Giantama, Seva

  pushArr("Rafli");
  popArr();
  changeArr("Rafli", 2);
  displayArr();
  // Syaikul, Rafli, Giantama, Seva

  destroyArr();
  displayArr();
  // Data kosong!

  return 0;
}

bool isFull()
{
  return top >= maks;
}

bool isEmpty()
{
  return top <= 0;
}

void pushArr(string data)
{
  if (isFull())
    cout << "Data full! \n\n";
  else
  {
    arrMhs[top] = data;
    top++;
  }
}

void popArr()
{
  if (isEmpty())
    cout << "Data kosong! \n\n";
  else
  {
    arrMhs[top - 1] = "";
    top--;
  }
}

int peekArr(int posisi)
{
  if (isEmpty())
  {
    cout << "Data masih kosong! \n";
    return -1;
  }
  else if (posisi > maks)
  {
    cout << "Data tidak ditemukan! \n";
    return -1;
  }
  else
  {
    int index = top;
    for (int i = 0; i < posisi; i++)
      index--;
    return index;
  }
}

int countArr()
{
  return top;
}

void changeArr(string newData, int posisi)
{
  int index = peekArr(posisi);

  if (index != -1)
    arrMhs[index] = newData;
}

void destroyArr()
{
  for (int i = 0; i < top; i++)
    arrMhs[i] = "";
  top = 0;
}

void displayArr()
{
  cout << "Jumlah data: " << countArr() << "\n";
  if (isEmpty())
    cout << "Data kosong! \n";
  else
  {
    int num = 1;

    cout << "Data array: \n";
    for (int i = maks - 1; i >= 0; i--)
    {
      if (arrMhs[i] != "")
      {
        cout << num << ". " << arrMhs[i] << "\n";
        num++;
      }
    }
  }
  cout << "\n";
}