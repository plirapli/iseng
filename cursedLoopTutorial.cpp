#include <iostream>

using namespace std;

int main()
{
	int input;
	string username, password, nim = "123210084";

	do
	{
		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		if (username != nim || password != "62" + nim)
			cout << "Username atau password anda salah! \n\n";

	} while (username != nim || password != "62" + nim);

	cout << "Selamat datang! \n";

	cout << "input > ";
	cin >> input;

	int jmlBarisKolom = 2 * input - 2;

	int indexGanjil = 0;

	for (int baris = 0; baris < jmlBarisKolom; baris++)
	{
		if (baris % 2 == 0)
		{
			for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
			{
				if (kolom < (jmlBarisKolom - baris) / 2 || kolom > ((jmlBarisKolom - baris) / 2 - 1 + baris))
					cout << "* ";
				else
					cout << "  ";
			}
		}
		else
		{
			indexGanjil++;
			for (int kolom = 0; kolom < jmlBarisKolom; kolom++)
			{
				if (kolom < indexGanjil || kolom >= jmlBarisKolom - indexGanjil)
					cout << "* ";
				else
					cout << "  ";
			}
		}
		cout << "\n";
	}

	return 0;
}
