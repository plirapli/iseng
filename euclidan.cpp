#include <iostream>
#include <math.h>

using namespace std;

void inputPoint(int point[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dimensi ke-" << i + 1 << ": ";
		cin >> point[i];
	}
}

int main()
{
	int i, jmlDimensi;
	double sum;

	cout << "Masukkan jumlah dimensi: ";
	cin >> jmlDimensi;

	int x[jmlDimensi], y[jmlDimensi], res[jmlDimensi];

	cout << "\n"
			 << "titik x:"
			 << "\n";
	inputPoint(x, jmlDimensi);

	cout << "\n"
			 << "titik y:"
			 << "\n";
	inputPoint(y, jmlDimensi);

	for (i = 0; i < jmlDimensi; i++)
	{
		res[i] = pow((x[i] - y[i]), 2);
		sum += res[i];
	}

	cout << "\n"
			 << "Result: " << pow(sum, 0.5);

	return 0;
}