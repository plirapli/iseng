#include <iostream>

using namespace std;

void banyakPecahan(int uang, int pecahan[], int lembar[]);

int main()
{
	int uang, lembar[10] = {},
						pecahan[10] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};

	cout << "Jumlah uang kembali: Rp ";
	cin >> uang;

	cout << "Pecahan uang kembali: \n";
	banyakPecahan(uang, pecahan, lembar);

	return 0;
}

void banyakPecahan(int uang, int pecahan[], int lembar[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (uang - pecahan[i] >= 0)
		{
			uang -= pecahan[i];
			lembar[i]++;
			i--;
		}
	}

	for (i = 0; i < 10; i++)
		if (lembar[i] >= 1)
			cout << lembar[i] << " lembar " << pecahan[i] << "\n";

	cout << "Jumlah yang didonasikan: Rp" << uang;
}
