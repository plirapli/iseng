#include <iostream>

using namespace std;

int main()
{
	int input;
	string username, passwd, nim = "123210078";

	// do
	// {
	// 	cout << "Username \t : ";
	// 	cin >> username;

	// 	cout << "Password \t : ";
	// 	cin >> passwd;

	// 	if (username != nim || passwd != "62" + nim)
	// 		cout << "Username atau password anda salah! \n\n";

	// } while (username != nim || passwd != "62" + nim);
	// cout << "Terima kasih";

	cout << "Input: ";
	cin >> input;

	int oddIndex = 0;
	int evenIndex = 10;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 != 0)
		{
			oddIndex++;
			for (int j = 0; j < 10; j++)
			{
				if (j < oddIndex || j > 9 - oddIndex)
					cout << "* ";
				else
					cout << "  ";
			}
		}
		else
		{
			for (int j = 10; j > 0; j--)
			{
				// 10 9 8 7 6 > 5
				// 10 9 8 7 > 6
				// 10 9 8 > 7
				// 10 9 > 8
				// 10 > 9

				// < 5
				// 5 4 3 2 1 >= 5 - 0
				// 6 5 4 3 2 1 <= 6 - 2
				// 3 2 1 <= 7 - 4
				// 2 1 <= 8
				// 1 <= 9
				if (j > evenIndex / 2 || j <= evenIndex / 2 - i)
					cout << "* ";
				else
					cout << "  ";
			}
			evenIndex += 2;
		}
		cout << "\n";
	}

	return 0;
}