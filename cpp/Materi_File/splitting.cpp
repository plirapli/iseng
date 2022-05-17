// merge sambung file, asumsi sudah ada file pertama dan kedua yang akan disambung, data berisi data integer
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

FILE *Bil1, *Bil2, *Bil3;

int main()
{
  char namaFile[20], splitFile1[20], splitFile2[20];
  int i;

  cout << "Nama file: ";
  cin >> namaFile;
  cout << "Nama file ke-1 hasil splitting: ";
  cin >> splitFile1;
  cout << "Nama file ke-2 hasil splitting: ";
  cin >> splitFile2;

  Bil1 = fopen(namaFile, "r");
  Bil2 = fopen(splitFile1, "w");
  Bil3 = fopen(splitFile2, "w");

  // Error Handling
  if (Bil1 == NULL || Bil2 == NULL || Bil3 == NULL)
  {
    cout << "File gagal!\n ";
    exit(1);
  }

  while (fread(&i, sizeof(i), 1, Bil1) == 1)
  {
    if (i < 55)
      fwrite(&i, sizeof(i), 1, Bil2);
    else
      fwrite(&i, sizeof(i), 1, Bil3);
  }

  fclose(Bil1);
  fclose(Bil2);
  fclose(Bil3);

  return 0;
}