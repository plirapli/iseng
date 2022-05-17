// membaca data bilangan integer yang
// ada di file dari contoh program 1
#include <stdio.h>
#include <iostream>
using namespace std;

FILE *Bil;

int main()
{
  int i, j = 0;
  char namaFile[20];

  cout << "Nama File: ";
  cin >> namaFile;

  if ((Bil = fopen(namaFile, "r")) == NULL)
  {
    cout << "File tdk dpt dibuka!\n ";
    exit(1);
  }

  while (fread(&i, sizeof(i), 1, Bil) == 1)
    cout << "Bil ke-" << ++j << " = " << i << endl;

  fclose(Bil);

  return 0;
}
