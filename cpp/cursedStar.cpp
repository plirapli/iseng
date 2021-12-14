#include <iostream>

using namespace std;

int main()
{
	int jmlBarisKolom;
	cout << "Masukkan jumlah kolom dan baris: ";
	cin >> jmlBarisKolom;

	// * half py left align (standard)
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (kolom <= baris)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	// cout << "\n";

	// // * hollow half py left align
	// for (int i = 0; i < t; i++)
	// {
	// 	for (int j = 0; j <= i; j++)
	// 	{
	// 		if (i == t - 1 || j == 0 || i == j)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// * inverted half py left align
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (kolom < jmlBarisKolom - baris)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	// cout << "\n";

	// // * hollow inverted half py left align
	// for (int i = t; i > 0; i--)
	// {
	// 	for (int j = 0; j < i; j++)
	// 	{
	// 		if (i == t || j == i - 1 || j == 0)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * right align
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (j < 9 - i)
	// 			cout << "  ";
	// 		else
	// 			cout << "* ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * hollow right align
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (i == 9 || j == 9 - i || j == 9)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * inverted right align
	// for (int i = 10; i > 0; i--)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (j < 10 - i)
	// 			cout << "  ";
	// 		else
	// 			cout << "* ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * inverted hollow right align
	// for (int i = 10; i > 0; i--)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (i == 10 || j == 10 - i || j == 9)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * triangle
	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (j < 4 - i || j > 4 + i)
	// 			cout << "  ";
	// 		else
	// 			cout << "* ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (j < 4 - i || j > 4 + 1)
	// 			cout << "  ";
	// 		else if (i % 2 == 0)
	// 			cout << "* ";
	// 		else
	// 			cout << " *";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * hollow triangle
	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 9; j++)
	// 	{
	// 		if (i == 4 || j == 4 - i || j == 4 + i)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * inverted triangle
	// for (int i = 5; i > 0; i--)
	// {
	// 	for (int j = 0; j < 9; j++)
	// 	{
	// 		if (j < 5 - i || j >= 4 + i)
	// 			cout << "  ";
	// 		else
	// 			cout << "* ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * inverted hollow triangle
	// for (int i = 10; i > 0; i--)
	// {
	// 	for (int j = 0; j < 19; j++)
	// 	{
	// 		if (i == 10 || j == 10 - i || j == 8 + i)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * hollow square star pattern with diagonal
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (i == 0 || i == 9 || j == 9 - i || j == i || j == 0 || j == 9)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	// // * N with rectangle
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		if (i == 0 || i == 9 || j == 0 || j == 9 || i == j)
	// 			cout << "* ";
	// 		else
	// 			cout << "  ";
	// 	}
	// 	cout << "\n";
	// }

	return 0;
}