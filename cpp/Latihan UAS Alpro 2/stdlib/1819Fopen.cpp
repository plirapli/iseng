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
  DataMhs mhs[100], temp[100];
  int jml = 0, tempJml = 8;

  p1 = fopen("Kelas1.txt", "r");
  p2 = fopen("Kelas2.txt", "r");
  p3 = fopen("Remidi.txt", "w");

  for (int i = 0; i < tempJml; i++)
  {
    if (i < 4)
      fread(&temp[i], sizeof(temp[i]), 1, p1);
    else
      fread(&temp[i], sizeof(temp[i]), 1, p2);
  }

  // cout << "Kelas1.txt \n";
  // for (int i = 0; i < 4; i++)
  //   cout << temp[i].nim << " = " << temp[i].nilai << "\n";

  // cout << "\n"
  //      << "Kelas2.txt \n";
  // for (int i = 4; i < 8; i++)
  //   cout << temp[i].nim << " = " << temp[i].nilai << "\n";

  for (int i = 0; i < tempJml; i++)
  {
    if (temp[i].nilai <= 50)
    {
      mhs[jml] = temp[i];
      jml++;
    }
  }

  // cout << "\n"
  //      << "Remdidi.txt \n";
  // for (int i = 0; i < jml; i++)
  //   cout << mhs[i].nim << " = " << mhs[i].nilai << "\n";

  for (int i = 0; i < jml; i++)
    fwrite(&mhs[i], sizeof(mhs[i]), 1, p3);

  return 0;
}