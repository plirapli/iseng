#include <iostream>
#include <string>

using namespace std;

int main()
{
	string newData;
	int i, arrLength, dataAdded = 0, dataEdited;
	char inMenu;

	cout << "Masukkan jumlah data (lebih dari 2): ";
	cin >> arrLength;

	string data[arrLength];
	int arrSize = sizeof(data) / sizeof(data[0]);

	do
	{
		cout << "Menu : \n"
				 << "[1] Read Data \n"
				 << "[2] Add Data \n"
				 << "[3] Edit Data \n"
				 << "[0] Delete Data \n"
				 << "[Others] Exit \n"
				 << "Choose > ";
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

		if (inMenu == '0')
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

		cout << "\n";
	} while (inMenu >= '0' && inMenu <= '3');

	cout << "Terima kasih.";
	return 0;
}