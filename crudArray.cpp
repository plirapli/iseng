#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void readData(int length, string data[][3], string datafield[]);

int main()
{
	string newData;
	string menu[5] = {"[1] Read Data", "[2] Add Data", "[3] Edit Data", "[4] Delete Data", "[0] Exit"};
	string dataField[3] = {"Nama", "Alamat", "Umur"};
	int i, arrLength, found, dataAdded = 0, dataEdited;
	char inMenu;

	do
	{
		cout << "Masukkan jumlah data (lebih dari 2): ";
		cin >> arrLength;

		if (arrLength <= 2)
			cout << "Data harus lebih dari 2! \n";

	} while (arrLength <= 2);

	string data[arrLength][3];

	do
	{
		cout << "Menu : \n";
		for (i = 0; i < 5; i++)
			cout << menu[i] + "\n";

		cout << "Choose > ";
		cin >> inMenu;
		cin.ignore();

		if (inMenu == '1')
		{
			readData(arrLength, data, dataField);
		}

		if (inMenu == '2')
		{
			if (dataAdded < arrLength)
			{

				for (i = 0; i < 3; i++)
				{
					cout << dataField[i] + ": ";
					getline(cin, data[dataAdded][i]);
				}

				dataAdded++;
				cout << "Data Added! \n";

				readData(arrLength, data, dataField);
			}
			else
				cout << "Data telah melebihi kapasitas! \n";
		}

		// if (inMenu == '3')
		// {
		// 	found = 0;
		// 	for (i = 0; i < arrLength; i++)
		// 	{
		// 		if (data[i] != "")
		// 			found++;
		// 	}

		// 	if (found >= 1)
		// 	{
		// 		do
		// 		{
		// 			cout << "Data ke: ";
		// 			cin >> dataEdited;

		// 			if (dataEdited == 0)
		// 				cout << "Data tidak ditemukan. \n";

		// 		} while (dataEdited == 0);

		// 		cout << "Data baru: ";
		// 		cin >> newData;

		// 		data[dataEdited - 1] = newData;
		// 		cout << "Data Edited! \n";
		// 	}
		// 	else
		// 		cout << "Data tidak ada. \n";
		// }

		// if (inMenu == '4')
		// {
		// 	found = 0;
		// 	for (i = 0; i < arrLength; i++)
		// 	{
		// 		if (data[i] != "")
		// 			found++;
		// 	}

		// 	if (found >= 1)
		// 	{
		// 		do
		// 		{
		// 			cout << "Data ke: ";
		// 			cin >> dataEdited;

		// 			if (dataEdited == 0 || data[dataEdited - 1] == "")
		// 				cout << "Data tidak ditemukan. \n";

		// 		} while (dataEdited == 0 || data[dataEdited - 1] == "");

		// 		data[dataEdited - 1] = "";
		// 		cout << "Data Deleted!";
		// 	}
		// 	else
		// 		cout << "Data tidak ada. \n";
		// }

		if (inMenu > '4')
			cout << "Menu tidak ada! \n";

		cout << "\n";
	} while (inMenu != '0');

	cout << "Terima kasih.";
	return 0;
}

void readData(int length, string data[][3], string dataField[])
{
	int i;
	// Mencari jumlah kata terbanyak di setiap field
	int totalColLength, colLength[3] = {4, 6, 4};
	for (i = 0; i < length; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int dataLength = data[i][j].length();
			colLength[j] = (dataLength > colLength[j]) ? dataLength : colLength[j];
		}
	}
	totalColLength = colLength[0] + colLength[1] + colLength[2];

	cout << "Data saat ini: \n";
	cout << "| No | ";
	for (i = 0; i < 3; i++)
		cout << left << setw(colLength[i] + 1) << dataField[i] << "| ";

	cout << "\n";

	for (i = 0; i < length; i++)
	{
		cout << "| " << i + 1 << "  | ";
		for (int j = 0; j < 3; j++)
		{
			string res = (data[i][j] == "") ? "-" : data[i][j];
			string separator = (j >= 3) ? "|" : "| ";
			cout << left << setw(colLength[j] + 1) << res << separator;
		}
		cout << "\n";
	}
}