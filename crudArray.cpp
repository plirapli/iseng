#include <iostream>
#include <string>

using namespace std;

int main()
{
	string newData;
	string menu[5] = {"[1] Read Data", "[2] Add Data", "[3] Edit Data", "[4] Delete Data", "[0] Exit"};
	int i, arrLength, dataAdded = 0, dataEdited;
	char inMenu;

	cout << "Masukkan jumlah data (lebih dari 2): ";
	cin >> arrLength;

	string data[arrLength];
	int arrSize = sizeof(data) / sizeof(data[0]);

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
			for (i = 0; i < arrSize; i++)
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
			do
			{
				cout << "Data ke: ";
				cin >> dataEdited;

				if (data[dataEdited - 1] == "")
					cout << "Data tidak ditemukan.";

			} while (data[dataEdited - 1] == "");

			cout << "Data baru: ";
			cin >> newData;

			data[dataEdited - 1] = newData;
			cout << "Data Edited!";
		}

		if (inMenu == '4')
		{
			do
			{
				cout << "Data ke: ";
				cin >> dataEdited;

				if (data[dataEdited - 1] == "")
					cout << "Data tidak ditemukan.";

			} while (data[dataEdited - 1] == "");

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