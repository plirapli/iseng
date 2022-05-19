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
  int totalPesanan;
  string nama;
  Pemesan pemesan[100];
};

void add(User user[], int id);
// int search(Pemesan pemesan[], int n, string input);
int searching(User user[], int n, string input);

string replaceSpasi(string str);
string replaceHyphen(string str);
void pressAnyKey();

int main()
{
  User user[100];
  char inMenu;
  bool isExit = 0;
  int userCount = 0;

  do
  {
    cout << "Menu: \n"
         << "[1] Input Data \n"
         << "[2] Liat (Lokal) \n"
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
      int jmlProduk = 0, userIndex, id;
      string fileName, nama;

      cout << "INPUT DATA \n";
      cout << "Atas nama siapa, Kak? ";
      cin.ignore();
      getline(cin, nama);

      userIndex = searching(user, userCount, nama);

      if (userIndex != -1)
        id = userIndex;
      else
      {
        id = userCount;
        user[id].nama = nama;
        user[id].totalPesanan = 0;
        userCount++;
      }

      add(user, id);

      cout << user[id].totalPesanan << " ";
      cout << user[id].nama << "\n";

      fileName = replaceSpasi(user[id].nama) + ".txt";

      ofstream myFile(fileName);
      if (myFile.is_open())
      {
        for (int i = 0; i < user[id].totalPesanan; i++)
        {
          // Contoh format file:
          // pupus_1 pupus@email.com 08123456789 20000 depok banguntapan 4 16000

          myFile << user[id].pemesan[i].username << " "
                 << user[id].pemesan[i].email << " "
                 << user[id].pemesan[i].noHp << " "
                 << user[id].pemesan[i].saldo << " "
                 << user[id].pemesan[i].dataLokasi.lokasi << " "
                 << user[id].pemesan[i].dataLokasi.tujuan << " "
                 << user[id].pemesan[i].dataLokasi.jarak << " "
                 << user[id].pemesan[i].dataLokasi.tarif
                 << "\n";
        }
        myFile.close();
      }

      break;
    }

    case '2':
    {
      for (int i = 0; i < userCount; i++)
      {
        cout << "Nama: " << user[i].nama << "\n";

        for (int j = 0; j < user[i].totalPesanan; j++)
        {
          int saldo = user[i].pemesan[j].saldo;
          int tarif = user[i].pemesan[j].dataLokasi.tarif;

          cout << "Pemesan ke-" << j + 1 << "\n"
               << "Username: " << user[i].pemesan[j].username << "\n"
               << "Email: " << user[i].pemesan[j].email << "\n"
               << "No. HP: " << user[i].pemesan[j].noHp << "\n"
               << "Saldo Anda: " << saldo << "\n";

          cout << "Pesanan: \n"
               << "- Asal: " << user[i].pemesan[j].dataLokasi.lokasi << "\n"
               << "- Tujuan: " << user[i].pemesan[j].dataLokasi.tujuan << "\n"
               << "- Jarik (km): " << user[i].pemesan[j].dataLokasi.jarak << "\n"
               << "- Tarif (km): " << tarif << "\n";

          if (saldo > tarif)
            cout << "Pembayaran via saldo: Rp" << tarif << "\n";
          else
          {
            cout << "Pembayaran via saldo: Rp" << saldo << "\n"
                 << "Pembayaran via tunai: Rp" << tarif - saldo << "\n";
          }
          cout << "\n";
        }
      }

      break;
    }

      // case '2':
      // {
      //   Pemesan pemesan[5];
      //   int userIndex;
      //   string fileName, username;

      //   cout << "Pemesanan atas nama siapa kak? ";
      //   cin.ignore();
      //   getline(cin, fileName);

      //   fileName = replaceSpasi(fileName) + ".txt";

      //   ifstream myFile(fileName);
      //   int jmlData = 0;

      //   if (myFile.is_open())
      //   {
      //     int i = jmlData;
      //     while (!myFile.eof())
      //     {
      //       myFile >> pemesan[i].username >> pemesan[i].email >> pemesan[i].noHp;
      //       myFile >> pemesan[i].saldo;
      //       myFile >> pemesan[i].dataLokasi.lokasi >> pemesan[i].dataLokasi.tujuan;
      //       myFile >> pemesan[i].dataLokasi.jarak >> pemesan[i].dataLokasi.tarif;
      //       i++;
      //     }

      //     jmlData += i - 1;
      //     myFile.close();

      //     cout << "Masukkan username: ";
      //     cin >> username;
      //     cout << "\n";

      //     userIndex = search(pemesan, jmlData, username);

      //     if (userIndex != -1)
      //     {
      //       cout << "Username: " << pemesan[userIndex].username << "\n"
      //            << "Email: " << pemesan[userIndex].email << "\n"
      //            << "No. HP: " << pemesan[userIndex].noHp << "\n"
      //            << "Saldo Anda: " << pemesan[userIndex].saldo << "\n";
      //     }
      //     else
      //       cout << "Tidak ditemukan. \n\n";
      //   }
      //   else
      //     cout << "Pemesanan atas nama " << fileName << " tidak ditemukan. \n";

      //   pressAnyKey();
      //   break;
      // }

    case '3':
    {
      Pemesan pemesan[5];
      string fileName;

      cout << "Pemesanan atas nama siapa kak? ";
      cin.ignore();
      getline(cin, fileName);
      cout << "\n";

      fileName = replaceSpasi(fileName) + ".txt";

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
          cout << "\n";
        }
      }
      else
        cout << "Pemesanan atas nama " << replaceHyphen(fileName) << " tidak ditemukan.";

      pressAnyKey();
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

void add(User user[], int id)
{
  int jmlPemesan, i;
  int total = user[id].totalPesanan;

  cout << "Banyaknya pemesan: ";
  cin >> jmlPemesan;

  user[id].totalPesanan += jmlPemesan;
  cout << user[id].totalPesanan << "\n";

  for (i = 0; i < jmlPemesan; i++)
  {
    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Username: ";
    cin >> user[id].pemesan[total + i].username;
    cout << "Email: ";
    cin >> user[id].pemesan[total + i].email;
    cout << "No. HP: ";
    cin >> user[id].pemesan[total + i].noHp;
    cout << "Saldo: ";
    cin >> user[id].pemesan[total + i].saldo;
    cout << "\n";
  }

  cout << "DATA PEMESANAN \n";
  for (i = 0; i < jmlPemesan; i++)
  {
    int jarak;
    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Lokasi: ";
    cin >> user[id].pemesan[total + i].dataLokasi.lokasi;
    cout << "Tujuan: ";
    cin >> user[id].pemesan[total + i].dataLokasi.tujuan;
    cout << "Jarak (km): ";
    cin >> user[id].pemesan[total + i].dataLokasi.jarak;

    jarak = user[id].pemesan[total + i].dataLokasi.jarak;

    user[id].pemesan[total + i].dataLokasi.tarif = jarak * 4000;
    cout << "\n";
  }

  for (i = 0; i < jmlPemesan; i++)
  {
    int saldo = user[id].pemesan[total + i].saldo;
    int tarif = user[id].pemesan[total + i].dataLokasi.tarif;

    cout << "Pemesan ke-" << i + 1 << "\n";
    cout << "Saldo: Rp" << saldo << "\n"
         << "Tarif: Rp" << tarif << "\n";

    if (saldo >= tarif)
      cout << "Pembayaran via saldo: Rp" << tarif << "\n";
    else
    {
      cout << "Pembayaran via saldo: Rp" << saldo << "\n"
           << "Pembayaran via tunai: Rp" << tarif - saldo << "\n";
    }
    cout << "\n";
  }

  cout << "Pemesanan berhasil dilakukan.";
  pressAnyKey();
}

// int search(Pemesan pemesan[], int n, string input)
// {
//   for (int i = 0; i < n; i++)
//     if (input == pemesan[i].username)
//       return i;
//   return -1;
// }

int searching(User user[], int n, string input)
{
  for (int i = 0; i < n; i++)
    if (replaceSpasi(input) == replaceSpasi(user[i].nama))
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