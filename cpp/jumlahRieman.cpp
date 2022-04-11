#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

float fungsiA(float x);
float fungsiB(float x);

int main()
{
  // Muhammad Rafli / 123210078

  char F;

  int awal, akhir, p;
  float h, a, xi;
  float total = 0;

  /* Keterangan variabel:
     awal = batas awal
     akhir = batas akhir
     p = jumlah partisi
     h = lebar persegi
     a = batas awal tiap persegi
     xi = nilai tengah tiap persegi
     total = jumlah riemann
  */

  // Ada 2 pilihan fungsi, user bisa memilih salah satu.
  cout << "[1] f(x) = x^2 + 3 \n"
       << "[2] f(x) = (x + 5)^(1/2) + 7 \n"
       << "Pilih fungsi > ";
  cin >> F;

  // User memasukkan batas awal
  cout << "\nMaukkan batas awal: ";
  cin >> awal;

  a = awal;

  // User memasukkan batas akhir
  cout << "Maukkan batas akhir: ";
  cin >> akhir;

  // User memasukkan jumlah bagian yang akan dipartisi
  cout << "Masukkan jumlah partisi: ";
  cin >> p;

  h = (float)(akhir - awal) / p;

  cout << "\nHasil \n";
  cout << "------------------------------------ \n";

  switch (F)
  {
  // Jika user memilih fungsi pertama :
  case '1':
    for (int i = 0; i < p; ++i)
    {
      xi = a + (h / 2);
      a += h;

      // Hasil luas tiap persegi dijumlahkan dan dimasukkan ke dalam variabel total
      total += (fungsiA(xi) * h);
    }
    cout << "f(x) = x^2 + 3 \n";
    break;

  // Jika user memilih fungsi kedua :
  case '2':
    for (int i = 0; i < p; ++i)
    {
      xi = a + (h / 2);
      a += h;

      // Hasil luas tiap persegi dijumlahkan dan dimasukkan ke dalam variabel total
      total += (fungsiB(xi) * h);
    }
    cout << "f(x) = (x + 5)^(1/2) + 7 \n";
    break;

  // Jika input user tidak valid :
  default:
    cout << "Input tidak valid! \n";
    break;
  }

  // Hasil akan ditampilkan di sini :
  if (total > 0)
  {
    cout << "Awal = " << awal << ", Akhir = " << akhir << ", Partisi = " << p << "\n";
    cout << "Jumlah Riemann: " << total << endl;
  }

  getch();

  return 0;
}

float fungsiA(float x)
{
  return x * x + 3;
}

float fungsiB(float x)
{
  return pow((x + 5), 0.5) + 7;
}