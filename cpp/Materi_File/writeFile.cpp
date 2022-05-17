#include <stdio.h>
#include <iostream>

using namespace std;

FILE *Bil;

bool Mark(int i);

main()
{
  int i, j = 1;
  char namaFile[20];

  cout << "Nama file: ";
  cin >> namaFile;

  Bil = fopen(namaFile, "w");
  cout << "Masukkan data bilangan, akhiri dengan 999\n";
  cout << "Bilangan : ";
  cin >> i;

  while (i != 999)
  {
    fwrite(&i, sizeof(i), 1, Bil);
    cout << "Bilangan ke-" << j++ << ": ";
    cin >> i;
  }

  fclose(Bil);
}

bool Mark(int i)
{
  return (i == 999);
}