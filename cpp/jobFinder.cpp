#include <iostream>
using namespace std;

int main()
{
	char jnsKelamin;
	string pend;
	int umur, prog, opt, sekre, mnjr;

	cout << "Jenis Kelamin L/P : ";
	cin >> jnsKelamin;

	cout << "Umur : ";
	cin >> umur;

	cout << "Tingkat Pendidikan : ";
	cin >> pend;

	if (jnsKelamin == 'L')
	{
		prog++;
		mnjr++;
		opt++;
	}
	else
	{
		sekre++;
		prog++;
		mnjr++;
	}

	if (umur >= 17 && umur <= 25)
	{
		opt++;
		sekre++;
		prog++;
	}
	else if (umur > 25 && umur <= 35)
	{
		opt++;
		sekre++;
		prog++;
		mnjr++;
	}
	else if (umur > 35 && umur <= 40)
	{
		prog++;
		mnjr++;
	}

	if (pend == "SMA")
	{
		opt++;
		sekre++;
	}
	else if (pend == "D3")
	{
		opt++;
		sekre++;
		prog++;
	}
	else if (pend == "S1")
	{
		sekre++;
		prog++;
		mnjr++;
	}
	else if (pend == "S2")
		mnjr++;

	cout << "Pekerjaraan yang Dapat Ditawarkan : ";
	if (opt == 3 || sekre == 3 || prog == 3 || mnjr == 3)
	{
		if (opt == 3)
			cout << "Operator \n";
		if (sekre == 3)
			cout << "Sekretaris ";
		if (prog == 3)
			cout << "Programmer \n";
		if (mnjr == 3)
			cout << "Manajer \n";
	}
	else
		cout << "Tidak Ada";

	return 0;
}
