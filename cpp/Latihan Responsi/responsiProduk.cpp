#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef struct
{
  string nama, jenis;
  int jml, harga;
} Produk;

void add(Produk produk[], int &n);
void bubbleSort(Produk produk[], int size);
int *search(Produk produk[], int n, string input);

string replaceSpasi(string str);
string replaceHyphen(string str);

int main()
{
  Produk produk[10];
  Produk temp[100];

  char inMenu;
  int jmlProduk = 0;
  bool isExit = 0;
  string fileName = "produk.txt";

  do
  {
    cout << "Menu: \n"
         << "[1] Input Data \n"
         << "[2] Output Data \n"
         << "[...] Exit \n"
         << "Pilih > ";
    cin >> inMenu;

    system("CLS");

    switch (inMenu)
    {
    case '1':
    {
      add(produk, jmlProduk);

      for (int i = 0; i < jmlProduk; i++)
        produk[i].nama = replaceSpasi(produk[i].nama);

      ofstream myFile(fileName);
      if (myFile.is_open())
      {
        for (int i = 0; i < jmlProduk; i++)
        {
          myFile << produk[i].nama << " " << produk[i].jenis << " "
                 << produk[i].jml << " " << produk[i].harga << "\n";
        }
        myFile.close();
      }

      break;
    }

    case '2':
    {
      cout << "Output Data \n"
           << "[1] Seluruh Data \n"
           << "[2] Cari Data \n"
           << "[...] Menu Utama \n"
           << "Pilih > ";
      cin >> inMenu;
      system("CLS");

      ifstream myFile(fileName);
      int jmlData = 0;

      if (myFile.is_open())
      {
        int i = jmlData;
        while (!myFile.eof())
        {
          myFile >> temp[i].nama >> temp[i].jenis >> temp[i].jml >> temp[i].harga;
          i++;
        }
        jmlData += i - 1;
        myFile.close();
      }

      for (int i = 0; i < jmlData; i++)
        temp[i].nama = replaceHyphen(temp[i].nama);

      bubbleSort(temp, jmlData);

      switch (inMenu)
      {
      case '1':
        cout << "Daftar Produk: \n";
        for (int i = 0; i < jmlData; i++)
        {
          cout << i + 1 << ". "
               << temp[i].nama << " (" << temp[i].jenis << "): "
               << temp[i].jml << " (Rp" << temp[i].harga << ") \n";
        }
        cout << "\n";
        break;

      case '2':
      {
        int *searchRes;
        int jmlRes;
        string jenis;

        cout << "Cari Jenis Makanan: ";
        cin >> jenis;

        searchRes = search(temp, jmlData, jenis);
        jmlRes = sizeof(searchRes) / sizeof(searchRes[0]);

        if (searchRes[1] == 0)
          jmlRes--;

        cout << "Produk dengan jenis: " << jenis << "\n";
        if (searchRes[0] != -1)
        {
          for (int i = 0; i < jmlRes; i++)
          {
            cout << i + 1 << ". "
                 << temp[searchRes[i]].nama
                 << " (" << temp[searchRes[i]].jenis << "): "
                 << temp[searchRes[i]].jml
                 << " (Rp" << temp[searchRes[i]].harga << ") \n";
          }
          cout << "\n";
        }
        else
          cout << "Tidak ditemukan. \n\n";

        delete[] searchRes;
        break;
      }

      default:
        break;
      }

      break;
    }

    default:
      cout << "Terima kasih.";
      isExit = 1;
      break;
    }
  } while (!isExit);

  return 0;
}

void add(Produk produk[], int &n)
{
  cout << "Tambah Produk \n";
  cout << "Nama: ";
  cin.ignore();
  getline(cin, produk[n].nama);

  cout << "Jenis [keripik, kue, minuman, souvenir, pakaian]: ";
  cin >> produk[n].jenis;

  cout << "Jumlah: ";
  cin >> produk[n].jml;

  cout << "Harga: ";
  cin >> produk[n].harga;

  cout << "Penduduk berhasil ditambahkan. \n\n";

  n++;
}

void bubbleSort(Produk produk[], int size)
{
  int i, j;
  Produk temp;

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (produk[j].jml > produk[j + 1].jml)
      {
        // Swap element
        temp = produk[j];
        produk[j] = produk[j + 1];
        produk[j + 1] = temp;
      }
    }
  }
}

int *search(Produk produk[], int n, string input)
{
  int *res = new int[100];
  int resIndex = 0;
  bool isFound = 0;

  for (int i = 0; i < n; i++)
  {
    if (input == produk[i].jenis)
    {
      isFound = 1;
      res[resIndex] = i;
      resIndex++;
    }
  }

  if (!isFound)
    res[0] = -1;

  return res;
}

string replaceSpasi(string str)
{
  for (int i = 0; i < str.length(); i++)
    if (str[i] == ' ')
      str[i] = '-';

  return str;
}

string replaceHyphen(string str)
{
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '-')
      str[i] = ' ';

  return str;
}