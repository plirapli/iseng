#include <iostream>

using namespace std;

int main()
{
	// Muhammad Rafli / 123210078

	int nilai;

	cout << "Masukkan nilai: ";
	cin >> nilai;

	if (nilai >= 85)
	{
		cout << "A";
	}
	else if (nilai >= 80 && nilai <= 84)
	{
		cout << "A-";
	}
	else if (nilai >= 75 && nilai <= 79)
	{
		cout << "B+";
	}
	else if (nilai >= 70 && nilai <= 74)
	{
		cout << "B";
	}
	else if (nilai >= 65 && nilai <= 69)
	{
		cout << "B-";
	}
	else if (nilai >= 60 && nilai <= 64)
	{
		cout << "C+";
	}
	else if (nilai >= 55 && nilai <= 59)
	{
		cout << "C";
	}
	else if (nilai >= 50 && nilai <= 54)
	{
		cout << "C-";
	}
	else if (nilai >= 40 && nilai < 50)
	{
		cout << "D";
	}
	else if (nilai < 40)
	{
		cout << "E";
	}
	else
	{
		cout << "Nilai yang anda masukkan tidak valid";
	}

	return 0;
}