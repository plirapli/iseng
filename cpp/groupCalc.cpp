#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int generateMember(int offset, int range, int seed);
void hitungGrup(int qty, int group, int first);

int main()
{
	int qty, group, firstMember;

	cout << "Jml. Anggota > ";
	cin >> qty;
	cout << "Kelompok > ";
	cin >> group;

	cout << "NIM Awal > ";
	cin >> firstMember;

	if (qty > group)
		hitungGrup(qty, group, firstMember);
	else
		cout << "Jumlah anggota invalid. \n";

	return 0;
}

int generateMember(int offset, int range, int seed)
{
	srand(seed);
	int res = offset + (rand() % range);
	return res;
}

void hitungGrup(int qty, int group, int firstMember)
{
	int m = (qty / group) + 1;
	int numbering;
	int noGroup = 1;

	for (int i = 0; i < group; i++)
	{
		numbering = 1;
		if (i != 0 && (qty % (m - 1) == 0))
		{
			cout << "Kelompok: " << noGroup << "\n";
			for (int j = 0; j < (m - 1); j++)
			{
				int seed = time(0) + j;
				cout << numbering << ". " << generateMember(firstMember, qty, seed) << "\n";
				numbering++;
			}
			// cout << m - 1 << " ";
			noGroup++;
			qty -= m - 1;
		}
		else
		{
			cout << "Kelompok: " << noGroup << "\n";
			for (int j = 0; j < m; j++)
			{
				int seed = time(0) + j + qty;
				cout << numbering << ". " << generateMember(firstMember, qty, seed) << "\n";
				numbering++;
			}
			// cout << m << " ";
			noGroup++;
			qty -= m;
		}
		cout << "\n";
	}
}