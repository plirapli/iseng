#include <iostream>

using namespace std;

int main()
{
	// Initialize variable
	int no, angka;
	char nama;

	// Input name and number
	cout << "Nomor = ";
	cin >> no;
	cout << "Nama = ";
	cin >> nama;
	cout << "\n";

	no %= 4;

	if (no < 2 && nama > 'k')
	{
		angka = no + 1;
		switch (angka)
		{
		case 1:
			angka = (angka + no) + no / 2 + 1;
			no = (angka + 1) * 2 + no;
			break;

		case 2:
			no = (angka + no) - no / 2;
			angka = angka * 2 + no;
			break;

		default:
			no = (angka + no) + no / 2;
			angka = angka * 2 + no;
			break;
		}
	}
	else
	{
		angka = no;
		switch (angka)
		{
		case 0:
			no = (angka + no) + no / 2 + 1;
			angka = (angka + 1) * 2 + no;
			break;

		case 1:
			angka = (angka + no) - no / 2 + 1;
			no = (angka + 1) * 2 - no;
			break;

		default:
			angka = (angka + no) + no / 2;
			no = angka * 2 + no;
			break;
		}
	}

	int hasil = (angka < 5) ? angka : no;

	cout << "Hasil = " << hasil;

	return 0;
}
