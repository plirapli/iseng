#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ordo[2][2] = {};

	for (int i = 0; i < 2; i++)
	{
		string textForm = "baris";
		string matriks = (i != 1) ? "A" : "B";

		for (int j = 0; j < 2; j++)
		{
			cout << "Masukkan " + textForm + " matriks " + matriks + ": ";
			cin >> ordo[i][j];
			textForm = "kolom";
		}
		cout << "\n";
	}

	if (ordo[0][1] == ordo[1][0])
	{
		int a[ordo[0][0]][ordo[0][1]], b[ordo[1][0]][ordo[1][1]];

		int rowC = ordo[0][0], colC = ordo[1][1];
		vector<vector<int>> c(rowC, vector<int>(colC, 0));

		// Input Matriks
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < ordo[i][0]; j++)
			{
				for (int k = 0; k < ordo[i][1]; k++)
				{
					if (i != 1)
					{
						cout << "Matriks A baris " << j + 1 << " kolom " << k + 1 << ": ";
						cin >> a[j][k];
					}
					else
					{
						cout << "Matriks B baris " << j + 1 << " kolom " << k + 1 << ": ";
						cin >> b[j][k];
					}
				}
			}
			cout << "\n";
		}

		// Read Matriks
		cout << "Matriks A: \n";
		for (int j = 0; j < ordo[0][0]; j++)
		{
			cout << "[ ";
			for (int k = 0; k < ordo[0][1]; k++)
				cout << a[j][k] << " ";
			cout << "] \n";
		}
		cout << "\n";

		cout << "Matriks B: \n";
		for (int j = 0; j < ordo[1][0]; j++)
		{
			cout << "[ ";
			for (int k = 0; k < ordo[1][1]; k++)
				cout << b[j][k] << " ";
			cout << "] \n";
		}
		cout << "\n";

		// multiplication process
		cout << "Hasil: \n";
		for (int i = 0; i < rowC; i++)
		{
			cout << "[ ";
			for (int j = 0; j < colC; j++)
			{
				for (int k = 0; k < ordo[0][1]; k++)
					c[i][j] += (a[i][k] * b[k][j]);
				cout << c[i][j] << " ";
			}
			cout << "] \n";
		}
	}
	else
		cout << "Tidak dapat melakukan perkalian.";

	return 0;
}