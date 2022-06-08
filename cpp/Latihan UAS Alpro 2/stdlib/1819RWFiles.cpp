#include <iostream>
#include <stdlib.h>

using namespace std;

struct DataMhs
{
  int nim, nilai;
};

FILE *p1, *p2, *p3;

int main()
{
  DataMhs mhs[100];
  int jml = 8, jmlFiltered = 4;
  int nilai[8] = {50, 75, 93, 48, 87, 32, 40, 65};

  p1 = fopen("Kelas1.txt", "w");
  p2 = fopen("Kelas2.txt", "w");
  p3 = fopen("Remidi.txt", "r");

  // for (int i = 0; i < jml; i++)
  // {
  //   if (i < 4)
  //     mhs[i].nim = 1001 + i;
  //   else
  //     mhs[i].nim = 1011 + i;
  // }

  // for (int i = 0; i < jml; i++)
  //   mhs[i].nilai = nilai[i];

  // for (int i = 0; i < jml; i++)
  // {
  //   if (i < 4)
  //     fwrite(&mhs[i], sizeof(mhs[i]), 1, p1);
  //   else
  //     fwrite(&mhs[i], sizeof(mhs[i]), 1, p2);
  // }

  for (int i = 0; i < jmlFiltered; i++)
    fread(&mhs[i], sizeof(mhs[i]), 1, p3);

  for (int i = 0; i < jmlFiltered; i++)
    cout << mhs[i].nim << " = " << mhs[i].nilai << "\n";

  return 0;
}