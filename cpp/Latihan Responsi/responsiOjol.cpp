#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct DataPemesan
{
  string lokasi, tujuan;
  int jarak, tarif;
};

struct Pemesan
{
  string username, email, noHp;
  int saldo;
  DataPemesan dataLokasi;
};

struct User
{
  int jmlPemesan;
  string nama;
  Pemesan pemesan[5];
};

void add(User user);
int search(Pemesan pemesan[], int n, string input);

string replaceSpasi(string str);
string replaceHyphen(string str);
void pressAnyKey();

int main()
{
  char inMenu;
  bool isExit = 0;

  do
  {
    cout << "Menu: \n"
         << "[1] Input Data \n"
         << "[2] Searching \n"
         << "[3] Cetak Receipt \n"
         << "[...] Exit \n"
         << "Pilih > ";
    cin >> inMenu;

    system("CLS");

    switch (inMenu)
    {

    case '1':
    {
      User user;
      int jmlProduk = 0;
      string fileName;

      add(user);

      user.nama = replaceSpasi(user.nama);

      fileName = user.nama + ".txt";

      ofstream myFile(fileName);
      if (myFile.is_open())
      {
        for (int i = 0; i < user.jmlPemesan; i++)
        {
          // pupus_1 pupus@email.com 08123456789 20000 depok banguntapan 4 16000
          myFile << user.pemesan[i].username << " "
                 << user.pemesan[i].email << " "
                 << user.pemesan[i].noHp << " "
                 << user.pemesan[i].saldo << " "
                 << user.pemesan[i].dataLokasi.lokasi << " "
                 << user.pemesan[i].dataLokasi.tujuan << " "
                 << user.pemesan[i].dataLokasi.jarak << " "
                 << user.pemesan[i].dataLokasi.tarif
                 << "\n";
        }
        myFile.close();
      }

      break;
    }

    case '2':
    {
      Pemesan pemesan[5];
      int userIndex;
      string fileName, username;

      cout << "Pemesanan atas nama siapa kak? ";
      cin >> fileName;

      ifstream myFile(replaceSpasi(fileName));
      int jmlData = 0;

      if (myFile.is_open())
      {

        int i = jmlData;
        while (!myFile.eof())
        {
          myFile >> pemesan[i].username >> pemesan[i].email >> pemesan[i].noHp;
          myFile >> pemesan[i].saldo;
          myFile >> pemesan[i].dataLokasi.lokasi >> pemesan[i].dataLokasi.tujuan;
          myFile >> pemesan[i].dataLokasi.jarak >> pemesan[i].dataLokasi.tarif;
          i++;
        }

        jmlData += i - 1;
        myFile.close();
      }
      else
        cout << "Pemesanan atas nama " << fileName << " tidak ditemukan. \n";

      cout << "Masukkan username: ";
      cin >> username;

      userIndex = search(pemesan, jmlData, username);

      if (userIndex != -1)
      {
        cout << "Username: " << pemesan[userIndex].username << "\n"
             << "Email: " << pemesan[userIndex].email << "\n"
             << "No. HP: " << pemesan[userIndex].noHp << "\n"
             << "Saldo Anda: " << pemesan[userIndex].saldo << "\n";
      }
      else
        cout << "Tidak ditemukan. \n\n";
    }

    case '3':
    {
      Pemesan pemesan[5];
      string fileName;

      cout << "Pemesanan atas nama siapa kak? ";
      cin >> fileName;

      fileName = replaceSpasi(fileName);

      ifstream myFile(fileName);
      int jmlData = 0;

      if (myFile.is_open())
      {
        int i = jmlData;
        while (!myFile.eof())
        {
          myFile >> pemesan[i].username >> pemesan[i].email >> pemesan[i].noHp;
          myFile >> pemesan[i].saldo;
          myFile >> pemesan[i].dataLokasi.lokasi >> pemesan[i].dataLokasi.tujuan;
          myFile >> pemesan[i].dataLokasi.jarak >> pemesan[i].dataLokasi.tarif;
          i++;
        }

        jmlData += i - 1;
        myFile.close();
      }

      for (int i = 0; i < jmlData; i++)
      {
        int saldo = pemesan[i].saldo;
        int tarif = pemesan[i].dataLokasi.tarif;

        cout << "Pemesan ke-" << i + 1 << "\n"
             << "Username: " << pemesan[i].username << "\n"
             << "Email: " << pemesan[i].email << "\n"
             << "No. HP: " << pemesan[i].noHp << "\n"
             << "Saldo Anda: " << saldo << "\n";

        cout << "Pesanan: \n"
             << "- Asal: " << pemesan[i].dataLokasi.lokasi << "\n"
             << "- Tujuan: " << pemesan[i].dataLokasi.tujuan << "\n"
             << "- Jarik (km): " << pemesan[i].dataLokasi.jarak << "\n"
             << "- Tarif (km): " << tarif << "\n";

        if (saldo > tarif)
          cout << "Pembayaran via saldo: Rp" << tarif << "\n";
        else
        {
          cout << "Pembayaran via saldo: Rp" << saldo << "\n"
               << "Pembayaran via tunai: Rp" << tarif - saldo << "\n";
        }
      }

      cout << "\n";
      pressAnyKey();
    }

    default:
      cout << "Terima kasih.";
      isExit = 1;
      break;
    }
  } while (!isExit);

  return 0;
}

void add(User user)
{
  cout << "INPUT DATA \n";
  cout << "Atas nama siapa, Kak? ";
  cin.ignore();
  getline(cin, user.nama);

  cout << "Banyaknya pemesan: ";
  cin >> user.jmlPemesan;

  for (int i = 0; i < user.jmlPemesan; i++)
  {
    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Username: ";
    cin >> user.pemesan[i].username;
    cout << "Email: ";
    cin >> user.pemesan[i].email;
    cout << "No. HP: ";
    cin >> user.pemesan[i].noHp;
    cout << "Saldo: ";
    cin >> user.pemesan[i].saldo;
    cout << "\n";
  }

  cout << "DATA PEMESANAN \n";
  for (int i = 0; i < user.jmlPemesan; i++)
  {
    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Lokasi: ";
    cin >> user.pemesan[i].dataLokasi.lokasi;
    cout << "Tujuan: ";
    cin >> user.pemesan[i].dataLokasi.tujuan;
    cout << "Jarak (km): ";
    cin >> user.pemesan[i].dataLokasi.jarak;

    user.pemesan[i].dataLokasi.tarif = user.pemesan[i].dataLokasi.jarak * 4000;
    cout << "\n";
  }

  for (int i = 0; i < user.jmlPemesan; i++)
  {
    int saldo = user.pemesan[i].saldo;
    int tarif = user.pemesan[i].dataLokasi.tarif;

    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Saldo: Rp" << saldo << "\n"
         << "Tarif: Rp" << tarif;

    if (saldo > tarif)
      cout << "Pembayaran via saldo: Rp" << tarif << "\n";
    else
    {
      cout << "Pembayaran via saldo: Rp" << saldo << "\n"
           << "Pembayaran via tunai: Rp" << tarif - saldo << "\n";
    }
  }

  cout << "\nPemesanan berhasil dilakukan. \n\n";
  pressAnyKey();
}

int search(Pemesan pemesan[], int n, string input)
{
  for (int i = 0; i < n; i++)
    if (input == pemesan[i].username)
      return i;
  return -1;
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

void pressAnyKey()
{
  cout << "\n"
       << "[Press any key to continue.]";
  getch();
  system("CLS");
}