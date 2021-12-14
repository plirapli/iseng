#include <iostream>
#include <string>
using namespace std;

int main()
{
	string jenjangStudi, prodi;
	int thnMasuk;
	string kode = "";

	cout << "6 digit NIM Generator untuk Mahasiswa FTI \n";
	cout << "List Jenjang studi : \n"
			 << "- S1 \n"
			 << "- D3 \n"
			 << "Jenjang Studi \t : ";
	getline(cin, jenjangStudi);

	cout << "\n";

	if (jenjangStudi == "S1")
	{
		kode = "12";

		cout << "List Prodi S1 : \n"
				 << "- Teknik Kimia \n"
				 << "- Teknik Industri \n"
				 << "- Informatika \n"
				 << "- Sistem Informasi \n"
				 << "Program Studi \t : ";
		getline(cin, prodi);

		if (prodi == "Teknik Kimia")
			kode += "1";
		else if (prodi == "Teknik Industri")
			kode += "2";
		else if (prodi == "Informatika")
			kode += "3";
		else if (prodi == "Sistem Informasi")
			kode += "4";
		else
			kode += "*";
	}
	else
		kode += "021";

	cout << "Tahun Masuk \t : ";
	cin >> thnMasuk;

	kode += to_string(thnMasuk % 1000) + "0";
	cout << "NIM anda: " << kode << "***";

	return 0;
}
