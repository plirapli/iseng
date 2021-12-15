#include <iostream>

using namespace std;

void hitungGrup(int n, int k);

int main()
{
	int n, k;

	cout << "n > ";
	cin >> n;
	cout << "k > ";
	cin >> k;

	hitungGrup(n, k);

	return 0;
}

void hitungGrup(int n, int k)
{
	int m = n / k;

	for (int i = 0; i < k; i++)
	{
		if (i != 0 && (n % (m + 1) == 0))
		{
			cout << m + 1 << " ";
			n -= (m + 1);
		}
		else
		{
			cout << m << " ";
			n -= m;
		}
	}
}