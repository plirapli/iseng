#include <iostream>

using namespace std;

void questionSymptom(int &outJmlPertanyaan, string symptom, char &outInput);

int main()
{
	char inputG, ulangiBaru, ulangi;
	string nim, tgl, nama, garis = "------------------------------------------";

	do
	{
		// Input pasien
		cout << garis << "\n";
		cout << "No. Diagnosa \t: ";
		getline(cin, nim);
		cout << "Tgl. Diagnosa \t: ";
		getline(cin, tgl);
		cout << "Nama Pasien \t: ";
		getline(cin, nama);
		cout << garis << "\n\n";

		do
		{
			int jmlPertanyaan = 0;
			string diagnosa = "TIDAK ADA HASIL";

			if (ulangiBaru == 't' || ulangiBaru == 'T')
			{
				cout << garis << "\n"
						 << "No. Diagnosa \t: " + nim << "\n"
						 << "Tgl. Diagnosa \t: " + tgl << "\n"
						 << "Nama Pasien \t: " + nama << "\n"
						 << garis << "\n\n";
			}

			// Start Pertanyaan
			cout << "PERTANYAAN GEJALA :";
			questionSymptom(jmlPertanyaan, "[G15] Tidak terasa sakit bila disentuh", inputG);

			if (inputG == 'Y' || inputG == 'y')
			{
				questionSymptom(jmlPertanyaan, "[G12] Berukuran kecil", inputG);

				if (inputG == 'Y' || inputG == 'y')
				{
					questionSymptom(jmlPertanyaan, "[G13] Berwarna putih", inputG);

					if (inputG == 'Y' || inputG == 'y')
						diagnosa = "[ P01 ] Whiteheads";
					else
					{
						questionSymptom(jmlPertanyaan, "[G14] Berwarna hitam", inputG);

						if (inputG == 'Y' || inputG == 'y')
							diagnosa = "[ P02 ] Blackheads";
						else
						{
							questionSymptom(jmlPertanyaan, "[G01] Berwarna merah", inputG);

							if (inputG == 'Y' || inputG == 'y')
							{
								questionSymptom(jmlPertanyaan, "[G03] Memliki jumlah yang banyak", inputG);

								if (inputG == 'Y' || inputG == 'y')
									diagnosa = "[ P03 ] Papule";
								else
								{
									questionSymptom(jmlPertanyaan, "[G04] Berwarna merah dipinggir dan putih ditengah", inputG);

									if (inputG == 'Y' || inputG == 'y')
									{
										questionSymptom(jmlPertanyaan, "[G02] Berisi putih seperti nasi", inputG);

										if (inputG == 'Y' || inputG == 'y')
											diagnosa = "[ P04 ] Postule";
									}
								}
							}
						}
					}
				}
			}
			else
			{
				questionSymptom(jmlPertanyaan, "[G05] Berukuran Besar", inputG);

				if (inputG == 'Y' || inputG == 'y')
				{
					questionSymptom(jmlPertanyaan, "[G06] Terasa sakit bila disentuh", inputG);

					if (inputG == 'Y' || inputG == 'y')
						diagnosa = "[ P05 ] Nodule";
				}
				else
				{
					questionSymptom(jmlPertanyaan, "[G11] Menyebar ke bagian tubuh", inputG);

					if (inputG == 'Y' || inputG == 'y')
					{
						questionSymptom(jmlPertanyaan, "[G16] Bentuknya melebar", inputG);

						if (inputG == 'Y' || inputG == 'y')
							diagnosa = "[ P08 ] Acne rosacea";
					}
					else
					{
						questionSymptom(jmlPertanyaan, "[G09] Berbentuk bintik-bintik putih yang berukuran kecil dari komedo", inputG);

						if (inputG == 'Y' || inputG == 'y')
						{
							questionSymptom(jmlPertanyaan, "[G10] Terasa saat diraba", inputG);

							if (inputG == 'Y' || inputG == 'y')
								diagnosa = "[ P07 ] Milia";
						}
						else
						{
							questionSymptom(jmlPertanyaan, "[G07] Menyebar keseluruh wajah", inputG);

							if (inputG == 'Y' || inputG == 'y')
							{
								questionSymptom(jmlPertanyaan, "[G08] Berbentuk tonjolan yang meradang", inputG);

								if (inputG == 'Y' || inputG == 'y')
									diagnosa = "[ P06 ] Cyst";
							}
						}
					}
				}
			}
			// End Pertanyaan

			// Hasil diagnosa
			cout << "\nJumlah Pertanyaan Gejala = " << jmlPertanyaan
					 << "\n" + garis + "\n"
					 << "No. Diagnosa \t : " + nim + "\n"
					 << "Tgl. Diagnosa \t : " << tgl << "\n"
					 << "Nama Pasien \t : " << nama
					 << "\n" + garis + "\n"
					 << "HASIL DIAGNOSA PENYAKIT JERAWAT: \n" + diagnosa + "\n" + garis;

			// Ulangi?
			cout << "\n\n"
					 << "Ulangi Lagi (Y/T) ? > ";
			cin >> ulangi;

			if (ulangi == 'y' || ulangi == 'Y')
			{
				cout << "Input Pasien Baru (Y/T) ? ";
				cin >> ulangiBaru;
				cin.ignore();

				system("cls");
			}
			else
			{
				ulangiBaru = '\0';
				cout << "\n"
						 << "Terima Kasih.";
			}

		} while (ulangiBaru == 't' || ulangiBaru == 'T');
	} while (ulangiBaru == 'y' || ulangiBaru == 'Y');

	return 0;
}

void questionSymptom(int &outJmlPertanyaan, string symptom, char &outInput)
{
	outJmlPertanyaan++;
	cout << "\n\n"
			 << outJmlPertanyaan << ". Apakah Anda mengalami gejala " + symptom + "? \n"
			 << "   BENAR (Y) / SALAH (T) ? ";
	cin >> outInput;
}
