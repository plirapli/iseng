#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int i, j, size;
  char again;

  do
  {
    cout << "==========================================================================================\n"
         << "!!! Tips !!! ==> Input 7 atau 10 atau 13 ... dst (tambah 3 angka) supaya hasilnya SEMPURNA\n"
         << "==========================================================================================\n"
         << "Input > ";
    cin >> size;

    for (i = 1; i <= size + (size - 1) / 3; i++)
    {
      for (j = 1; j <= 2 * size - 1; j++)
      {
        if (
            i == size || i == (size - 1) / 3 + 1 || j + i == size + 1 || j == size + i - 1 ||
            i > (size - 1) / 3 + 1 && i < size && (j == i - (size - 1) / 3 || j + i == 2 * size + (size - 1) / 3) ||
            i > size && (j == i - (size - 1) / 3 || j + i == 2 * size + (size - 1) / 3))
          cout << "* ";
        else
          cout << "  ";
      }
      cout << "\n";
    }

    do
    {
      cout << "\n"
           << "Ingin melakukan input lagi (y / t) ? ";
      cin >> again;

      if (again == 'y')
        system("cls");
      else if (again != 'y' && again != 't')
        cout << "Maaf, kode yg Anda masukkan SALAH!";
    } while (again != 'y' && again != 't');

  } while (again == 'y');

  cout << "Terima Kasih :)";

  getch();

  return 0;
}