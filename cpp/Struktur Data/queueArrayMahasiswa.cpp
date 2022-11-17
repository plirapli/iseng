#include <iostream>
#include <conio.h>

using namespace std;

const int maxArr = 50;

struct Mahasiswa
{
  int nim;
  string nama;
};

struct typequeue
{
  int belakang;
  Mahasiswa mhs[maxArr];
} queue;

void buat();                     // Untuk menginisiasi antrian
void enqueue(Mahasiswa newInfo); // Menambah antrian
void dequeue();                  // Menghapus antrian
void cetak();                    // Mencetak antrian

// Cek kondisi queue
bool isEmpty() { return queue.belakang == 0; }
bool isFull() { return queue.belakang == maxArr; }

// Misc
void pressAnyKey()
{
  cout << "[Tekan tombol apa saja untuk melanjutkan.]";
  getch();
}

int main()
{
  char input;
  bool loop = 1;

  buat();
  do
  {
    system("cls");
    cout << "Data Mahasiswa \n"
         << "[1] Input Mahasiswa \n"
         << "[2] Lihat Mahasiswa \n"
         << "[3] Hapus Mahasiswa \n"
         << "[...] Kembali \n"
         << "Input > ";
    cin >> input;

    system("cls");
    switch (input)
    {
    case '1':
    {
      Mahasiswa inputData;
      int jml = 0;

      cout << "Banyak data > ";
      cin >> jml;

      for (int i = 0; i < jml; i++)
      {
        system("cls");

        cout << "NIM Mahasiswa > ";
        cin >> inputData.nim;

        cin.ignore();
        cout << "Nama Mahasiswa > ";
        getline(cin, inputData.nama);

        enqueue(inputData);
        cout << "\nBerhasil menambahkan data! \n";
        pressAnyKey();
      }
      break;
    }

    case '2':
      cetak();
      pressAnyKey();
      break;

    case '3':
      dequeue();
      cout << "Berhasil menghapus data! \n";
      pressAnyKey();
      break;

    default:
      loop = 0;
      break;
    }
  } while (loop);

  cout << "Terima kasih \n";

  return 0;
}

void buat() { queue.belakang = 0; }

void enqueue(Mahasiswa newInfo)
{
  if (isFull())
    cout << "Queue Overflow! \n";
  else
  {
    queue.belakang++;                    // Menambah antrian
    queue.mhs[queue.belakang] = newInfo; // Memasukkan data ke antrian paling belakang
  }
}

void dequeue()
{
  if (isEmpty())
    cout << "Queue Underflow! \n";
  else
  {
    Mahasiswa infoDequeue;
    int i;

    infoDequeue = queue.mhs[1];

    // Menampilkan Data yang mau dihapus
    cout << "Data yang akan dihapus: \n"
         << "[" << infoDequeue.nim << "] " << infoDequeue.nama << "\n";
    pressAnyKey();
    cout << "\n\n";

    for (i = 1; i < queue.belakang; i++)
      queue.mhs[i] = queue.mhs[i + 1];
    queue.belakang--;
  }
}

void cetak()
{
  int i = 1;
  while (i <= queue.belakang)
  {
    cout << i << ". [" << queue.mhs[i].nim << "] "
         << queue.mhs[i].nama << "\n";
    i++;
  }
}
