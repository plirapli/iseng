#include <iostream>
#include <string>

using namespace std;

int main()
{
	float diskon;
	int receiptID, inputCode, inputPrice, inputQty, priceTotal, paymentTotal, pay, change;
	string username, passwd, date, buyerName, inputProduct, member, memberId, anotherTransaction;

	string productCode[5] = {"001", "002", "003", "004", "005"};
	string productName[5] = {"Paracetamol", "Amoxillin", "Combantrin", "Tolak Angin/Box", "Mixagrip"};
	int productPrice[5] = {50000, 16000, 25000, 33000, 3000};

	do
	{
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> passwd;

		if (username != "mrafli" || passwd != "123")
			cout << "Username atau Password anda salah!";
		else
			cout << "Login Berhasil!";

		cout << "\n\n";

	} while (username != "mrafli" || passwd != "123");

	do
	{
		cout << "Nomor Transaksi: ";
		cin >> receiptID;

		cout << "Tanggal Transaksi (DD-MM-YY): ";
		cin >> date;
		cin.ignore();

		cout << "Nama Pembeli: ";
		getline(cin, buyerName);

		cout << "\n";

		for (int i = 0; i < 5; i++)
		{
			cout << productCode[i] << "\t"
					 << productName[i] << "\t"
					 << "Rp" << productPrice[i] << ",-"
					 << "\n";
		}

		cout << "\n";

		do
		{
			cout << "Kode Produk: ";
			cin >> inputCode;

			switch (inputCode)
			{
			case 1:
				inputProduct = productName[0];
				inputPrice = productPrice[0];
				break;

			case 2:
				inputProduct = productName[1];
				inputPrice = productPrice[1];
				break;

			case 3:
				inputProduct = productName[2];
				inputPrice = productPrice[2];
				break;

			case 4:
				inputProduct = productName[3];
				inputPrice = productPrice[3];
				break;

			case 5:
				inputProduct = productName[4];
				inputPrice = productPrice[4];
				break;

			default:
				cout << "\n"
						 << "Kode Produk tidak ditemukan!"
						 << "\n";
				break;
			}
		} while (!(inputCode >= 1 && inputCode <= 5));

		cout << "Nama Produk: " << inputProduct << "\n"
				 << "Harga Produk: "
				 << "Rp" << inputPrice << ",-"
				 << "\n";

		cout << "Jumlah Produk: ";
		cin >> inputQty;

		priceTotal = inputPrice * inputQty;

		cout << "Total Harga: " << priceTotal << "\n\n";

		cout << "Ada kartu member? (y/n): ";
		cin >> member;

		if (member == "y")
		{
			cout << "ID Member: ";
			cin >> memberId;

			diskon = (priceTotal >= 350000) ? priceTotal * 15 / 100 : 0;
		}
		else
			diskon = (priceTotal >= 3500) ? priceTotal * 15 / 100 : 0;

		paymentTotal = priceTotal - diskon;

		cout << "\n";

		cout << "Diskon: " << diskon << "\n"
				 << "Total Bayar: " << paymentTotal << "\n";

		cout << "Bayar: ";
		cin >> pay;

		change = pay - paymentTotal;

		cout << "Kembali: " << change << "\n\n";

		// Nota
		cout << "===== NOTA ====="
				 << "\n"
				 << "Nomor Transaksi\t"
				 << ": " << receiptID << "\n"
				 << "Tgl Transaksi\t"
				 << ": " << date << "\n"
				 << "Nama Pembeli\t"
				 << ": " << buyerName << "\n"
				 << "Kode Produk\t"
				 << ": " << inputCode << "\n"
				 << "Nama Produk\t"
				 << ": " << inputProduct << "\n"
				 << "Harga Produk\t"
				 << ": " << inputPrice << "\n"
				 << "Jumlah Produk\t"
				 << ": " << inputQty << "\n"
				 << "Total Harga\t"
				 << ": "
				 << "Rp" << priceTotal << ",-"
				 << "\n"
				 << "Diskon\t\t"
				 << ": "
				 << "Rp" << diskon << ",-"
				 << "\n"
				 << "Total Bayar\t"
				 << ": "
				 << "Rp" << paymentTotal << ",-"
				 << "\n"
				 << "Bayar\t\t"
				 << ": "
				 << "Rp" << pay << ",-"
				 << "\n"
				 << "Kembali\t\t"
				 << ": "
				 << "Rp" << change << ",-"
				 << "\n";

		do
		{
			cout << "Ingin melakukan transaksi lain? (y/n) : ";
			cin >> anotherTransaction;

			if (anotherTransaction != "y" && anotherTransaction != "n")
				cout << "Jawaban tidak valid!"
						 << "\n";

		} while (anotherTransaction != "y" && anotherTransaction != "n");

	} while (anotherTransaction == "y");

	cout << "Terima kasih.";

	return 0;
}