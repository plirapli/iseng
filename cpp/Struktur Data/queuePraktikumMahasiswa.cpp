#include <iostream>
#include <conio.h>

using namespace std;

struct Mahasiswa
{
  int nim;
  string nama;
};

struct typequeue
{
  Mahasiswa mhs;
  typequeue *next;
} * antrianDepan, *antrianBelakang;

void buat();                     // Untuk menginisiasi antrian
void enqueue(Mahasiswa newInfo); // Menambah antrian
void dequeue();                  // Menghapus antrian
void cetak();                    // Mencetak antrian

// Cek kondisi antrian
bool isEmpty() { return antrianDepan == NULL; }

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

void buat()
{
  antrianDepan = new typequeue;
  antrianDepan = NULL;
  antrianBelakang = antrianDepan;
}

void enqueue(Mahasiswa newInfo)
{
  typequeue *newNode;

  // Membuat node baru
  newNode = new typequeue;
  newNode->mhs = newInfo;

  // Kalo antrian depan gaada, node baru jadi antrian depan
  if (antrianDepan == NULL)
    antrianDepan = newNode;
  else // Kalo antrian depan ada, node baru ditaro di antrian paling belakang
    antrianBelakang->next = newNode;

  antrianBelakang = newNode; // Node baru jadi antrian paling belakang
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

    // Menampilkan Data yang mau dihapus
    cout << "Data yang akan dihapus: \n"
         << "[" << hapus->mhs.nim << "] " << hapus->mhs.nama << "\n";
    pressAnyKey();
    cout << "\n\n";

    antrianDepan = hapus->next; // antrian paling depan pindah ke belakangnya
    delete hapus;               // menghapus antrian paling depan
  }
}

void cetak()
{
  typequeue *bantu;
  int i = 1;

  bantu = antrianDepan;
  do
  {
    cout << i << ". [" << bantu->mhs.nim << "] "
         << bantu->mhs.nama << "\n";
    bantu = bantu->next;
    i++;
  } while (bantu != NULL);
  cout << "\n";
}