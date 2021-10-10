#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int login, option, i;
	string username, passwd;
	vector<vector<string>> dbVec =
			{{"admin", "123"}};

	do
	{
		cout << "[1] Sign In \n"
				 << "[2] Sign Up \n"
				 << "[3] Lihat daftar user \n"
				 << "[Others] Exit \n"
				 << "Choose: ";
		cin >> option;

		if (option == 1)
		{
			do
			{
				cout << "Sign In \n";
				cout << "Username: ";
				cin >> username;

				cout << "Password: ";
				cin >> passwd;

				cout << "\n";

				for (int i = 0; i < 3; i++)
				{
					int checking = 0;
					checking = (username == dbVec[i][0] && passwd == dbVec[i][1]) ? 1 : 0;
					login += checking;
				}

				if (login >= 1)
				{
					cout << "Login Berhasil! \n\n";
				}
				else
					cout << "Username atau Password Anda Salah! \n\n";
			} while (login == 0);

			if (login >= 1)
				break;
		}
		else if (option == 2)
		{
			cout << "Sign Up \n";
			cout << "Add Username: ";
			cin >> username;

			cout << "Add Password: ";
			cin >> passwd;

			int size = dbVec.size();
			dbVec.push_back(vector<string>());
			dbVec[size].insert(dbVec[size].end(), {username, passwd});

			cout << "User added! \n\n";
		}
		else if (option == 3)
		{
			for (int i = 0; i < dbVec.size(); i++)
			{
				cout << "username: " << dbVec[i][0] << "\n"
						 << "password: " << dbVec[i][1] << "\n\n";
			}
		}
		else
			cout << "Keluar Program. \n";
	} while (option < 4);

	cout << "Terima kasih.";

	return 0;
}