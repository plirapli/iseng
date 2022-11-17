#include <iostream>
using namespace std;

int main()
{
  int a, b = 10, *p, *q; // Deklarasi Variabel

  p = new int(sizeof(int)); // Mengalokasikan memori pada variabel p

  a = b * 2 + b / 2; // a memiliki nilai 25
  *p = a + b;        // p memiliki nilai a + b = 35
  q = &b;            // q menunjuk b

  cout << "Nilai a = " << a << "\n"
       << "Nilai a + b = " << *p << "\n"
       << "Nilai q = " << *q;

  return 0;
}