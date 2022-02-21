#include <iostream>

using namespace std;

int main()
{
	int n, S = 0;

	cout << "Jumlah Suku n: ";
	cin >> n;

	cout << "S = ";
	for (int i = 1; i <= n; i++)
	{
		string operasi;
		if (i % 5 == 0 && i != n)
			operasi = " + ";
		else if (i == n)
			operasi = " ";
		else
			operasi = " - ";

		int tanda = (i % 5 == 0) ? 1 : -1;
		S += (3 * i * tanda);

		cout << 3 * i << operasi;
	}
	cout << "= " << S;

	return 0;
}