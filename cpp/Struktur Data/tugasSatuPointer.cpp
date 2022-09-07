#include <iostream>

using namespace std;

int main()
{
  int a, b = 10, *p, *q;

  p = new int(sizeof(int));

  a = b * 2 + b / 2;
  *p = a + b;
  q = &b;

  cout << "Nilai a = " << a << "\n"
       << "Nilai a + b = " << *p << "\n"
       << "Nilai q = " << *q;

  return 0;
}