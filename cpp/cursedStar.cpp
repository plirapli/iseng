#include <iostream>

using namespace std;

int main()
{
	int jmlBarisKolom;
	cout << "Masukkan jumlah kolom dan baris (bilangan ganjil): ";
	cin >> jmlBarisKolom;

	// SEGITIGA SIKU-SIKU
	// * segitiga siku (left align)
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

	cout << "\n";

	// * segitiga siku (left align) bolong
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom <= baris; kolom++)
		{
			if (baris == jmlBarisKolom - 1 || kolom == 0 || baris == kolom)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga siku kebalik (left align)
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

	cout << "\n";

	// * segitiga siku kebalik (left align) bolong
	for (int baris = jmlBarisKolom; baris > 0; baris--)
	{
		for (int kolom = 0; kolom < baris; kolom++)
		{
			if (baris == jmlBarisKolom || kolom == baris - 1 || kolom == 0)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga siku (right align)
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (kolom < jmlBarisKolom - 1 - baris)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga siku (right align) bolong
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (baris == jmlBarisKolom - 1 || kolom == jmlBarisKolom - 1 - baris || kolom == jmlBarisKolom - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga siku kebalik (right align)
	for (int baris = jmlBarisKolom; baris > 0; baris--)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (kolom < jmlBarisKolom - baris)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga siku kebalik (right align) bolong
	for (int baris = jmlBarisKolom; baris > 0; baris--)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (baris == jmlBarisKolom || kolom == jmlBarisKolom - baris || kolom == jmlBarisKolom - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// SEGITIGA SAMA KAKI
	int jmlBaris = jmlBarisKolom;
	int jmlKolomBarisTerakhir = jmlBarisKolom * 2;

	// * segitiga sama kaki
	for (int baris = 0; baris < jmlBaris; baris++)
	{
		for (int kolom = 0; kolom < jmlKolomBarisTerakhir; kolom++)
		{
			if (kolom < jmlBaris - 1 - baris || kolom > jmlBaris - 1 + baris)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga sama kaki bolong
	for (int baris = 0; baris < jmlBaris; baris++)
	{
		for (int kolom = 0; kolom < jmlKolomBarisTerakhir - 1; kolom++)
		{
			if (baris == jmlBaris - 1 || kolom == jmlBaris - 1 - baris || kolom == jmlBaris - 1 + baris)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga sama kaki kebalik
	for (int baris = jmlBaris; baris > 0; baris--)
	{
		for (int kolom = 0; kolom < jmlKolomBarisTerakhir - 1; kolom++)
		{
			if (kolom < jmlBaris - baris || kolom >= jmlBaris - 1 + baris)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * segitiga sama kaki kebalik bolong
	for (int baris = jmlBaris; baris > 0; baris--)
	{
		for (int kolom = 0; kolom < jmlKolomBarisTerakhir - 1; kolom++)
		{
			if (baris == jmlBaris || kolom == jmlBaris - baris || kolom == jmlBaris - 2 + baris)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// KOTAK
	// * Kotak silang di tengah
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (baris == 0 ||
					baris == jmlBarisKolom - 1 ||
					kolom == jmlBarisKolom - 1 - baris ||
					kolom == baris ||
					kolom == 0 ||
					kolom == jmlBarisKolom - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * Kotak diagonal di tengah
	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
		{
			if (baris == 0 ||
					baris == jmlBarisKolom - 1 ||
					kolom == 0 ||
					kolom == jmlBarisKolom - 1 ||
					baris == kolom)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	return 0;
}