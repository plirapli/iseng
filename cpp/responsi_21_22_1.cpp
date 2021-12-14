#include <iostream>
#include <iomanip>

using namespace std;

int sum(int n1, int n2);
int sub(int n1, int n2);
int multi(int n1, int n2);
float div(float n1, float n2);
int pow(int n1, int n2);
int factorial(int n1);

float g_log[20][6] = {};
int g_jmlLog[6] = {};

int main()
{
	bool ulangMenu = 1, ulangCalc = 1;
	char menuEnum, op;
	int i, j;
	float n1, n2, res;
	string logField[6] = {"Tambah", "Kurang", "Kali", "Bagi", "Pangkat", "Faktor"};

	do
	{
		ulangCalc = 1;

		cout << "[1] Kalkulator \n"
				 << "[2] Log Perhitungan \n"
				 << "[Others] Keluar \n"
				 << "Pilih > ";
		cin >> menuEnum;

		switch (menuEnum)
		{
		// Program Kalkulator
		case '1':
		{
			do
			{
				cout << "Masukkan angka pertama: ";
				cin >> n1;
				cout << "Masukkan angka kedua: ";
				cin >> n2;
				cout << "Masukkan operator: ";
				cin >> op;

				switch (op)
				{
				case '+':
					cout << "Hasil: " << sum(n1, n2) << "\n";
					break;

				case '-':
					cout << "Hasil: " << sub(n1, n2) << "\n";
					break;

				case '*':
					cout << "Hasil: " << multi(n1, n2) << "\n";
					break;

				case '/':
					cout << "Hasil: " << div(n1, n2) << "\n";
					break;

				case '^':
					if (n2 < 0)
						cout << "Bilangan ke-2 harus positif! \n";
					else
					{

						res = pow(n1, n2);

						if (g_jmlLog[4] >= 20)
							g_jmlLog[4] = 0;

						g_log[g_jmlLog[4]][4] = res;
						g_jmlLog[4]++;

						cout << "Hasil: " << res << "\n";
					}
					break;

				case '!':
					if (n1 < 0)
						cout << "Bilangan harus positif! \n";
					else
					{
						res = factorial(n1);

						if (g_jmlLog[5] >= 20)
							g_jmlLog[5] = 0;

						g_log[g_jmlLog[5]][5] = res;
						g_jmlLog[5]++;

						cout << "Hasil: " << res << "\n";
					}
					break;

				default:
					cout << "Operator tidak valid. \n";
					break;
				}

				cout << "Ulangi? (y/n) > ";
				cin >> menuEnum;

				cout << "\n";

				if (menuEnum == 'n' || menuEnum == 'N')
					ulangCalc = 0;

			} while (ulangCalc == 1);

			break;
		}

		// Menampilkan tabel history perhitungan
		case '2':
		{
			int jmlGaris = 90;
			string garis = "=";

			cout << "History: \n";

			for (int i = 0; i < jmlGaris; i++)
				cout << garis;
			cout << "\n";

			cout << "| " << left << setw(3) << "No"
					 << "| ";
			for (i = 0; i < 6; i++)
				cout << left << setw(12) << logField[i] << "| ";

			cout << "\n";

			for (int i = 0; i < jmlGaris; i++)
				cout << garis;
			cout << "\n";

			for (i = 0; i < 20; i++)
			{
				cout << "| " << left << setw(3) << i + 1 << "| ";
				for (j = 0; j < 6; j++)
					cout << left << setw(12) << g_log[i][j] << "| ";

				cout << "\n";
			}

			for (int i = 0; i < jmlGaris; i++)
				cout << garis;
			cout << "\n\n";

			break;
		}

		default:
			ulangMenu = 0;
			break;
		}
	} while (ulangMenu == 1);

	cout << "Terima kasih.";

	return 0;
}

int sum(int n1, int n2)
{
	int res = n1 + n2;

	// Jika index melebihi 20, reset menjadi 0
	if (g_jmlLog[0] >= 20)
		g_jmlLog[0] = 0;

	g_log[g_jmlLog[0]][0] = res;

	// Index pertama bertambah
	g_jmlLog[0]++;

	return res;
}

int sub(int n1, int n2)
{
	int res = n1 - n2;

	if (g_jmlLog[1] >= 20)
		g_jmlLog[1] = 0;

	g_log[g_jmlLog[1]][1] = res;
	g_jmlLog[1]++;

	return res;
}

int multi(int n1, int n2)
{
	int res = n1 * n2;

	if (g_jmlLog[2] >= 20)
		g_jmlLog[2] = 0;

	g_log[g_jmlLog[2]][2] = res;
	g_jmlLog[2]++;

	return res;
}

float div(float n1, float n2)
{
	float res = n1 / n2;

	if (g_jmlLog[3] >= 20)
		g_jmlLog[3] = 0;

	g_log[g_jmlLog[3]][3] = res;
	g_jmlLog[3]++;

	return res;
}

int pow(int n1, int n2)
{
	if (n2 > 0)
		return n1 * pow(n1, n2 - 1);
	else
		return 1;
}

int factorial(int n1)
{
	if (n1 > 1)
		return n1 * factorial(n1 - 1);
	else
		return 1;
}