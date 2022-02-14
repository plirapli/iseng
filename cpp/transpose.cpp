#include <iostream>

using namespace std;

int main()
{
	int a[2][3] = {
			{2, 3, 6},
			{4, 7, 8}};

	int bt[3][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			bt[i][j] = a[j][i];
			cout << bt[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}