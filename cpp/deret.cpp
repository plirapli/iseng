#include <iostream>
#include <iomanip>

using namespace std;

void deret1(int n);
void deret2(int n);
void deret3(int n);
void deret4(int n);
void deret5(int n);

int deretA(int n);
int deretB(int n);

float pangkat(int base, int n);

int main()
{
	int n;

	cout << "Jumlah Suku n: ";
	cin >> n;
	cout << "\n";

	cout << "Relasi Rekurensi: \n";
	deret1(n);
	cout << "\n";
	deret2(n);
	cout << "\n";
	deret3(n);
	cout << "\n";
	deret4(n);
	cout << "\n";
	deret5(n);
	cout << "\n\n";

	cout << "Rekursi: \n"
			 << "Deret A: S =  " << deretA(n) << "\n"
			 << "Deret B: S =  " << deretB(n) << "\n";

	return 0;
}

void deret1(int n)
{
	int S = 0, tanda;
	char operasi;

	cout << "Deret 1: S = ";
	for (int i = 1; i <= n; i++)
	{
		operasi = (i % 5 == 0) ? '+' : '-';

		tanda = (i % 5 == 0) ? 1 : -1;
		S += (3 * i * tanda);

		cout << operasi << 3 * i;
	}
	cout << " = " << S;
}

void deret2(int n)
{
	int S = 0, tanda;
	char operasi;

	cout << "Deret 2: S = ";
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			operasi = '-';
		else if (i == 1)
			operasi = ' ';
		else
			operasi = '+';

		tanda = (i % 2 == 0) ? -1 : 1;
		S += ((2 * i - 1) * tanda);

		cout << operasi << 2 * i - 1;
	}
	cout << " = " << S;
}

void deret3(int n)
{
	int tanda;
	float S = 0;
	char operasi;

	cout << "Deret 3: S = ";
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			operasi = '-';
		else if (i == 1)
			operasi = ' ';
		else
			operasi = '+';

		tanda = (i % 2 == 0) ? -1 : 1;
		S += (1.0 / i * tanda);

		cout << operasi << "1/" << i;
	}
	cout << " = " << setprecision(2) << S;
}

void deret4(int n)
{
	int tanda;
	float S = 0;
	char operasi;

	cout << "Deret 4: S = ";
	for (int i = 1; i <= n; i++)
	{
		operasi = (i % 4 == 0) ? '+' : '-';

		tanda = (i % 4 == 0) ? 1 : -1;
		S += (1.0 / (i * 2) * tanda);

		cout << operasi << "1/" << i * 2;
	}
	cout << " = " << setprecision(3) << S;
}

void deret5(int n)
{
	int tanda;
	float S = 0;
	char operasi;

	cout << "Deret 5: S = ";
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
			operasi = '-';
		else if (i == 1)
			operasi = ' ';
		else
			operasi = '+';

		tanda = (i % 3 == 0) ? -1 : 1;
		S += (pangkat(2, i) / pangkat(3, i) * tanda);

		cout << operasi << pangkat(2, i) << "/" << pangkat(3, i);
	}
	cout << " = " << setprecision(3) << S;
}

int deretA(int n)
{
	if (n != 1)
	{
		cout << n << "+";
		return n + deretA(n - 1);
	}
	else
	{
		cout << 1 << " = ";
		return 1;
	}
}

int deretB(int n)
{
	if (n != 1)
	{
		cout << 2 * n << "+";
		return 2 * n + deretB(n - 1);
	}
	else
	{
		cout << 2 << " = ";
		return 2;
	}
}

float pangkat(int base, int n)
{
	int jml = 1;
	for (int i = 0; i < n; i++)
		jml *= base;
	return jml;
}