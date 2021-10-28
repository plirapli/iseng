#include <iostream>

using namespace std;

int main()
{
	// Muhammad Rafli / 123210078
	int input, inputAwal, inputMenu, inputUlang;
	string username, passwd, nim = "123210078";

	do
	{
		cout << "[1] Login \n"
				 << "[Others] Exit \n"
				 << "Pilihan: ";
		cin >> inputAwal;

		if (inputAwal == 1)
		{
			do
			{
				cout << "Username \t : ";
				cin >> username;

				cout << "Password \t : ";
				cin >> passwd;

				if (username != nim || passwd != "62" + nim)
					cout << "Username atau password anda salah! \n\n";

			} while (username != nim || passwd != "62" + nim);

			cout << "Terima kasih \n\n";

			cout << "[1] Tampilkan Kode Rahasia \n"
					 << "[Others] Logout \n"
					 << "Pilihan: ";
			cin >> inputMenu;

			if (inputMenu == 1)
			{
				do
				{
					cout << "Input: ";
					cin >> input;
					cout << "\n"
							 << "Kode Rahasia : \n";

					int total = input * 2 - 2;
					int oddIndex = 0;

					for (int i = 0; i < total; i++)
					{
						oddIndex = (i % 2 != 0) ? oddIndex + 1 : oddIndex;
						for (int j = 0; j < total; j++)
						{
							if (i % 2 != 0)
							{
								if (j < oddIndex || j > (total - 1) - oddIndex)
									cout << "* ";
								else
									cout << "  ";
							}
							else
							{
								if (j < (total - i) / 2 || j > ((total - i) / 2 - 1 + i))
									cout << "* ";
								else
									cout << "  ";
							}
						}
						cout << "\n";
					}
					cout << "\n";

					cout << "[1] Ya \n"
							 << "[Others] Tidak \n"
							 << "Ingin memasukkan input yang lain? > ";
					cin >> inputUlang;
					cout << "\n";
				} while (inputUlang == 1);

				cout << "Terima kasih \n\n";
			}
			else
				cout << "Logout \n\n";
		}
	} while (inputAwal == 1);

	cout << "Terima kasih";

	return 0;
}