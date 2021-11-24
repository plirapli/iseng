#include <iostream>

using namespace std;

int main()
{
	int matriks1[2][5], matriks2[2][5], jml = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Matriks 1 baris ke-" << i + 1 << " kolom ke- " << j + 1 << " = ";
			cin >> matriks1[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Matriks 2 baris ke-" << i + 1 << " kolom ke- " << j + 1 << " = ";
			cin >> matriks2[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << matriks1[i][j] + matriks2[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
