#include <iostream>
#include <string>

using namespace std;

int main()
{
	string newData;
	string menu[5] = {"[1] Read Data", "[2] Add Data", "[3] Edit Data", "[4] Delete Data", "[0] Exit"};
	int i, arrLength, found, dataAdded = 0, dataEdited;
	char inMenu;

	do
	{
		cout << "Masukkan jumlah data (lebih dari 2): ";
		cin >> arrLength;

		if (arrLength <= 2)
			cout << "Data harus lebih dari 2! \n";

	} while (arrLength <= 2);

	string data[arrLength];

	do
	{
		cout << "Menu : \n";
		for (i = 0; i < 5; i++)
			cout << menu[i] + "\n";

		cout << "Choose > ";
		cin >> inMenu;

		if (inMenu == '1')
		{
			cout << "Data saat ini: \n";
			for (i = 0; i < arrLength; i++)
			{
				string res = (data[i] == "") ? "[Data tidak ada]." : data[i];
				cout << i + 1 << ". " + res + "\n";
			}
		}

		if (inMenu == '2')
		{
			cout << "Masukkan data > ";
			cin >> newData;

			data[dataAdded] = newData;
			dataAdded++;
			cout << "Data Added!";
		}

		if (inMenu == '3')
		{
			found = 0;
			for (i = 0; i < arrLength; i++)
			{
				if (data[i] != "")
					found++;
			}
			if (found >= 1)
			{
				do
				{
					cout << "Data ke: ";
					cin >> dataEdited;

					if (dataEdited == 0)
						cout << "Data tidak ditemukan. \n";

				} while (dataEdited == 0);

				cout << "Data baru: ";
				cin >> newData;

				data[dataEdited - 1] = newData;
				cout << "Data Edited!";
			}
			else
				cout << "Data tidak ada. \n";
		}

		if (inMenu == '4')
		{
			do
			{
				cout << "Data ke: ";
				cin >> dataEdited;

				if (dataEdited == 0 || data[dataEdited - 1] == "")
					cout << "Data tidak ditemukan. \n";

			} while (dataEdited == 0 || data[dataEdited - 1] == "");

			data[dataEdited - 1] = "";
			cout << "Data Deleted!";
		}

		if (inMenu > '4')
			cout << "Menu tidak ada! \n";

		cout << "\n";
	} while (inMenu != '0');

	cout << "Terima kasih.";
	return 0;
}