#include <iostream>
#include <string>

using namespace std;

int main()
{
	string newData;
	int i = 0, arrLength, dataAdded = 0, dataEdited;
	char inMenu;

	cout << "Masukkan jumlah data (lebih dari 2): ";
	cin >> arrLength;

	string data[arrLength];

	int arrSize = sizeof(data) / sizeof(data[0]);

	// cout << "Data saat ini: \n";
	// for (i = 0; i < 0; i++)
	// 	cout << data[i] + " ";
	// cout << "\n";

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
				cout << data[i] + " ";
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
			cout << "Data ke: ";
			cin >> dataEdited;
			cout << "Data baru: ";
			cin >> newData;

			data[dataEdited - 1] = newData;
			cout << "Data Edited!";
		}

		cout << "\n\n";
	} while (inMenu >= '0' && inMenu <= '3');

	cout << "Terima kasih.";

	return 0;
}