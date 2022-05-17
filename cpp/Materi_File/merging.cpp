// merge sambung file, asumsi sudah ada file pertama dan kedua yang akan disambung, data berisi data integer
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

FILE *Bil1, *Bil2, *Bil3;

int main()
{
  char namaFile1[20], namaFile2[20], namaFile3[20];
  int i;

  cout << "Nama file 1 = ";
  cin >> namaFile1;
  cout << "Nama file 2 = ";
  cin >> namaFile2;
  cout << "Nama file hasil merge sambung = ";
  cin >> namaFile3;

  Bil1 = fopen(namaFile1, "r");
  Bil2 = fopen(namaFile2, "r");
  Bil3 = fopen(namaFile3, "w");

  // Error Handling
  if (Bil1 == NULL || Bil2 == NULL || Bil3 == NULL)
  {
    cout << "File gagal!\n ";
    exit(1);
  }

  while (fread(&i, sizeof(i), 1, Bil1) == 1)
  {
    fwrite(&i, sizeof(i), 1, Bil3);
  }
  while (fread(&i, sizeof(i), 1, Bil2) == 1)
  {
    fwrite(&i, sizeof(i), 1, Bil3);
  }

  fclose(Bil1);
  fclose(Bil2);
  fclose(Bil3);

  return 0;
}