#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int generateMember(int offset, int range, int seed);
bool findNum(int num, int addedNum);
void hitungGrup(int qty, int group, int first);

int dbNum[100];

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

bool findNum(int num, int addedNum)
{
	for (int i = 0; i < addedNum; i++)
	{
		if (num == dbNum[i])
		{
			break;
			return false;
		}
	}
	return true;
}

void hitungGrup(int qty, int group, int firstMember)
{
	int m = (qty / group) + 1, newQty = qty, numbering, noGroup = 1, addedNum = 0;

	for (int i = 0; i < group; i++)
	{
		numbering = 1;
		if (i != 0 && (newQty % (m - 1) == 0))
		{
			cout << "Kelompok: " << noGroup << "\n";
			for (int j = 0; j < (m - 1); j++)
			{
				int seedGen = 0, seed, num;
				bool isAdded, checkNum;

				do
				{
					seed = time(0) + j + seedGen;
					num = generateMember(firstMember, qty, seed);
					checkNum = findNum(num, addedNum);

					if (checkNum == true)
					{
						isAdded == true;
						dbNum[addedNum] = num;
						addedNum++;
					}
					else
					{
						isAdded == false;
						seedGen++;
					}
				} while (isAdded == true);

				cout << numbering << ". " << num << "\n";
				numbering++;
			}
			// cout << m - 1 << " ";
			noGroup++;
			newQty -= m - 1;
		}
		else
		{
			cout << "Kelompok: " << noGroup << "\n";
			for (int j = 0; j < m; j++)
			{
				int seedGen = 0, seed, num;
				bool isAdded, checkNum;

				// do
				// {
				seed = time(0) + j + qty + seedGen;
				num = generateMember(firstMember, qty, seed);
				// 	checkNum = findNum(num, addedNum);

				// 	if (checkNum != true)
				// 	{
				// 		isAdded == false;
				// 		seedGen++;
				// 	}
				// 	else
				// 	{
				// 		isAdded == true;
				// 		dbNum[addedNum] = num;
				// 		addedNum++;
				// 	}
				// } while (isAdded == true);

				cout << numbering << ". " << num << "\n";
				seedGen++;
				numbering++;
			}
			// cout << m << " ";
			noGroup++;
			newQty -= m;
		}
		cout << "\n";
	}
}