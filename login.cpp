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
	int size = dbVec.size();

	do
	{
		cout << "Menu : \n"
				 << "[1] Sign In \n"
				 << "[2] Lihat daftar user \n"
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

				for (i = 0; i < dbVec.size(); i++)
				{
					int checking = 0;
					checking = (username == dbVec[i][0] && passwd == dbVec[i][1]) ? 1 : 0;
					login += checking;
				}

				if (login >= 1)
					cout << "Login Berhasil! \n\n";
				else
					cout << "Username atau Password Anda Salah! \n\n";
			} while (login == 0);

			if (login >= 1)
				break;
		}
		else if (option == 2)
		{
			int inputCrud;
			for (i = 0; i < dbVec.size(); i++)
			{
				cout << "Daftar User : \n"
						 << "username: " << dbVec[i][0] << "\n"
						 << "password: " << dbVec[i][1] << "\n\n";
			}
			cout << "[1] Tambah User \n"
					 << "[2] Edit User \n"
					 << "[3] Delete User \n"
					 << "[Others] Back \n"
					 << "Choose: ";
			cin >> inputCrud;

			switch (inputCrud)
			{
			case 1:
				cout << "Sign Up \n";
				cout << "Add Username: ";
				cin >> username;

				cout << "Add Password: ";
				cin >> passwd;

				dbVec.push_back(vector<string>());
				dbVec[size].insert(dbVec[size].end(), {username, passwd});

				cout << "User added! \n\n";
				break;

			case 2:
			{
				int inputUser;
				int inputEditUser;
				string inputNewUsername;
				string inputNewPasswd;

				cout << "Edit User : \n";
				for (i = 0; i < dbVec.size(); i++)
				{
					cout << "[" << i + 1 << "] "
							 << "user: " << dbVec[i][0]
							 << " / " << dbVec[i][1] << "\n";
				}
				cout << "Pilih User: ";
				cin >> inputUser;

				cout << "\n";

				cout << "User: " << dbVec[inputUser - 1][0]
						 << " / " << dbVec[inputUser - 1][1] << "\n"
						 << "[1] Edit username \n"
						 << "[2] Edit password \n"
						 << "[Others] Back \n"
						 << "Choose: ";
				cin >> inputEditUser;

				switch (inputEditUser)
				{
				case 1:
					cout << "\nCurrent Username: " << dbVec[inputUser - 1][0] << "\n"
							 << "New Username: ";
					cin >> inputNewUsername;

					cout << "Username changed \n\n";
					break;

				case 2:
					cout << "\nCurrent Password: " << dbVec[inputUser - 1][1] << "\n"
							 << "New Password: ";
					cin >> inputNewPasswd;

					cout << "Password changed! \n\n";
					break;

				default:
					cout << "Back. \n\n";
					break;
				}

				break;
			}

			default:
				cout << "Back \n";
				break;
			}
		}
		else
			cout << "Keluar Program. \n";
	} while (option < 3);

	cout << "Terima kasih.";

	return 0;
}