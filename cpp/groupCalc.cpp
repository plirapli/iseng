#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int noTransaksi(int offset, int range);
void hitungGrup(int qty, int group);

int main()
{
	int qty, group, firstNIM;

	cout << "Jml. Anggota > ";
	cin >> qty;
	cout << "Kelompok > ";
	cin >> group;

	cout << "NIM Awal > ";
	cin >> firstNIM;

	// if (qty > group)
	// 	hitungGrup(qty, group);
	// else
	// 	cout << "Jumlah anggota invalid. \n";

	cout << noTransaksi(firstNIM, qty);

	return 0;
}

int noTransaksi(int offset, int range)
{
	srand(time(0));
	int res = offset + (rand() % range);
	return res;
}

void hitungGrup(int qty, int group)
{
	int m = qty / group;

	for (int i = 0; i < group; i++)
	{
		if (i != 0 && (qty % (m + 1) == 0))
		{
			cout << m + 1 << " ";
			qty -= (m + 1);
		}
		else
		{
			cout << m << " ";
			qty -= m;
		}
	}
}