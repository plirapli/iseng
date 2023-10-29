#include <iostream>
using namespace std;

int main()
{
  string tes;
  // if (isalpha(tes[0]))
  // {
  //   cout << "hurup";
  // }

  cout << "Masukkan kunci: ";
  getline(cin, tes);

  cout << stoi(tes) + 1;
  return 0;
}
