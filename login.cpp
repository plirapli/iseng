#include <iostream>

using namespace std;

int main()
{
	int login;
	string db[3][2] =
			{
					{"admin", "123"},
					{"rafli", "151"},
					{"test", "101"}};

	string username, passwd;

	do
	{
		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> passwd;

		cout << "\n";

		for (int i = 0; i < 3; i++)
		{
			int checking = 0;
			checking = (username == db[i][0] && passwd == db[i][1]) ? 1 : 0;
			login += checking;
		}

		if (login >= 1)
			cout << "Login Berhasil! \n\n";
		else
			cout << "Login Gagal! \n\n";

	} while (login == 0);

	return 0;
}