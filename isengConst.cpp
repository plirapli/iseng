#include <iostream>

using namespace std;

int main()
{
	const int a = 3;

	auto f = []()
	{
		const int a = 4;
		return a;
	};

	cout << a << endl; // output 3
	cout << f();			 // output 4

	return 0;

	// variabel define tidak bisa di cout, const bisa
	// const bisa ditentukan scope-nya, sedangkan define tidak.
}