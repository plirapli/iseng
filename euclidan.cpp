#include <iostream>
#include <math.h>

using namespace std;

void inputPoint(float point[], int n)
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

	float a[jmlDimensi], b[jmlDimensi], res[jmlDimensi];

	cout << "\n"
			 << "titik A:"
			 << "\n";
	inputPoint(a, jmlDimensi);

	cout << "\n"
			 << "titik B:"
			 << "\n";
	inputPoint(b, jmlDimensi);

	for (i = 0; i < jmlDimensi; i++)
	{
		res[i] = pow((a[i] - b[i]), 2);
		sum += res[i];
	}

	cout << "\n"
			 << "Result: " << pow(sum, 0.5);

	return 0;
}
