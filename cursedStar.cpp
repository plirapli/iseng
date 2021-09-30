#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 10; i++) // N with Rectangle
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i == 0 || i == 9 || j == 0 || j == 10 || i == j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n\n";

	for (int i = 0; i < 10; i++) // * left align (standart)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (j < 10 - i)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}

	cout << "\n\n";

	for (int i = 0; i < 10; i++) // * right align
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j < 10 - i)
				cout << " ";
			else if (j >= 10 - i && j <= 10)
				cout << "*";

			if (j > 10 && j <= 10 + i)
				cout << "*";
		}
		cout << "\n";
	}

	return 0;
}