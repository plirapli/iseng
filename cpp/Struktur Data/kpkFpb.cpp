#include <iostream>

using namespace std;

int kpk(int a, int b)
{
  int kpk = 0;

  for (int i = 1; i <= b; i++)
  {
    kpk += a;
    if (kpk % b == 0)
      break;
  }

  return kpk;

  /*
  6, 8

  1 = 6, 6 % 8 != 0
  2 = 12, 12 % 8 != 0
  3 = 18, 18 % 8 != 0
  4 = 24, 24 % 8 != 0
  */
}

int fpb(int a, int b)
{
  int r = a % b;

  while (r != 0)
  {
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main()
{
  int a, b;

  cout << "masukkan bilangan pertama : ";
  cin >> a;
  cout << "masukkan bilangan kedua   : ";
  cin >> b;
  cout << "\n";

  cout << "KPK: " << kpk(a, b) << "\n";
  cout << "FPB: " << fpb(a, b);

  return 0;
}