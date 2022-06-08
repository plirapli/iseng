#include <iostream>
#include <fstream>

using namespace std;

struct DataMhs
{
  int nim, nilai;
};

void readFile(DataMhs mhs[], int &jml, string namaFile)
{
  DataMhs temp[100];

  ifstream myFile(namaFile);
  if (myFile.is_open())
  {
    int n = 0, j = jml, i = n;
    while (!myFile.eof())
    {
      myFile >> temp[i].nim >> temp[i].nilai;
      i++;
    }
    myFile.close();

    n = i - 1;

    for (i = 0; i < n; i++)
    {
      if (temp[i].nilai <= 50)
      {
        mhs[j] = temp[i];
        j++;
      }
    }
    jml = j;
  }
  else
    cout << "Gagal membuka file. \n";
}

void writeFile(DataMhs mhs[], int jml, string namaFile)
{
  ofstream myFile(namaFile);
  if (myFile.is_open())
  {
    for (int i = 0; i < jml; i++)
      myFile << mhs[i].nim << " " << mhs[i].nilai << "\n";
    myFile.close();
  }
  else
    cout << "File tidak dapat dibuka \n";
}

int main()
{
  DataMhs mhs[100];
  int jml = 0;

  readFile(mhs, jml, "Kelas1.txt");
  readFile(mhs, jml, "Kelas2.txt");
  writeFile(mhs, jml, "Remidi.txt");

  return 0;
}