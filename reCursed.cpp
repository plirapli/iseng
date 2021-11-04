#include <iostream>

using namespace std;

int rekursi(int a);
int penjumlahan(int a, int b);
int pengurangan(int a, int b);
int perkalian(int a, int b);
int pembagian(int a, int b);

int main()
{
	int a = 9, b = 2;
	cout << "rekursi: " << rekursi(a);
	// cout << "penjumlahan: " << penjumlahan(a, b) << "\n";
	// cout << "pengurangan: " << pengurangan(a, b) << "\n";
	// cout << "perkalian: " << perkalian(a, b) << "\n";
	// cout << "pembagian: " << pembagian(a, b) << "\n";

	return 0;
}

int rekursi(int a)
{
	if (a == 1)
	{
		cout << a << ": ";
		return a;
	}
	else
	{
		cout << a << " + ";
		return a + rekursi(a - 2);
	}
}

// rekursi(9) = 9 + rekursi(7)			 => 9 + 16 = 25
// 	rekursi(7) = 7 + rekursi(5)			 => 7 + 9 = 16
// 		rekursi(5) = 5 + rekursi(3)		 => 5 + 4 = 9
// 			rekursi(3) = 3 + rekursi(1)	 => 3 + 1 = 4
// 				rekursi(1) = 1						 => 1

int penjumlahan(int a, int b)
{
	return a + b;
}

int pengurangan(int a, int b)
{
	return a - b;
}

int perkalian(int a, int b)
{
	return a * b;
}

int pembagian(int a, int b)
{
	return a / b;
}