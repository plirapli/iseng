#include <iostream>
using namespace std;

// Menyimpan data buah
struct buah
{
  string nama;
  int harga;
} databuah[100];

// Fungsi Lihat Buah
void outputBuah(int jml)
{
  system("cls");
  cout << "OUTPUT DATA \n";
  cout << "Banyak data : " << jml << endl;

  for (int i = 0; i < jml; i++)
    cout << "Nama buah   : " << databuah[i].nama << "\n"
         << "Harga buah : " << databuah[i].harga << "\n\n";
}

// Fungsi Cari Buah
int searching(int jml, string input)
{
  for (int i = 0; i < jml; i++)
    if (input == databuah[i].nama)
      return i;
  return -1;
}

int main()
{
  char loop = 'y', input;
  int jml = 0;

  do
  {
    system("cls");
    cout << "Data Nama Buah \n"
         << "1. Input nama buah \n"
         << "2. Lihat nama buah \n"
         << "3. Beli buah \n"
         << "input : ";
    cin >> input;

    // Menu Input Buah
    if (input == '1')
    {
      system("cls");
      cout << "Banyak data : ";
      cin >> jml;

      for (int i = 0; i < jml; i++)
      {
        cin.ignore();

        cout << "Nama buah   : ";
        getline(cin, databuah[i].nama);

        cout << "Harga buah : ";
        cin >> databuah[i].harga;
        cout << "\n";
      }
    }

    // Menu Lihat Buah
    else if (input == '2')
      outputBuah(jml);

    // Menu BeliBuah
    else
    {
      string inputNama;
      int index, inputJml, hargaBuah;

      outputBuah(jml);

      cin.ignore();
      cout << "Pilih Nama Buah: ";
      getline(cin, inputNama);

      index = searching(jml, inputNama); // Mencari buah yang ingin dibeli

      // Jika buah ditemukan, maka masukkan jumlah buah yg ingin dibeli
      if (index != -1)
      {
        cout << "Masukkan jumlah: ";
        cin >> inputJml;

        hargaBuah = databuah[index].harga * inputJml;
        cout << "Harga: " << hargaBuah << "\n\n";
      }
      else
        cout << "Buah tidak ditemukan! \n\n";
    }

    cout << "Kembali ke menu ? (y/n) > ";
    cin >> loop;
  } while (loop == 'y');
}