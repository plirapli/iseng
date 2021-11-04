#include <iostream>

using namespace std;

void questionSymptom(int &outJmlPertanyaan, string symptom, char &outInput);

int main()
{
	char inputG, ulangiBaru, ulangi;
	string nim, tgl, nama,
			garis = "------------------------------------------",
			outG[17] =
					{
							"",
							"[G01] Berwarna merah",
							"[G02] Berisi putih seperti nasi",
							"[G03] Memliki jumlah yang banyak",
							"[G04] Berwarna merah dipinggir dan putih ditengah",
							"[G05] Berukuran Besar",
							"[G06] Terasa sakit bila disentuh",
							"[G07] Menyebar keseluruh wajah",
							"[G08] Berbentuk tonjolan yang meradang",
							"[G09] Berbentuk bintik-bintik putih yang berukuran kecil dari komedo",
							"[G10] Terasa saat diraba",
							"[G11] Menyebar ke bagian tubuh",
							"[G12] Berukuran kecil",
							"[G13] Berwarna putih",
							"[G14] Berwarna hitam",
							"[G15] Tidak terasa sakit bila disentuh",
							"[G16] Bentuknya melebar",
					},
			outP[9] =
					{"TIDAK ADA HASIL", "[ P01 ] Whiteheads", "[ P02 ] Blackheads",
					 "[ P03 ] Papule", "[ P04 ] Postule", "[ P05 ] Nodule", "[ P06 ] Cyst",
					 "[ P07 ] Milia", "[ P08 ] Acne rosacea"};

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

		string hasilDiagnosaText = "HASIL DIAGNOSA PENYAKIT JERAWAT (" + nama + "): \n";

		do
		{
			int jmlPertanyaan = 0;
			string diagnosa = outP[0];

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
			questionSymptom(jmlPertanyaan, outG[15], inputG);

			if (inputG == 'Y' || inputG == 'y')
			{
				questionSymptom(jmlPertanyaan, outG[12], inputG);

				if (inputG == 'Y' || inputG == 'y')
				{
					questionSymptom(jmlPertanyaan, outG[13], inputG);

					if (inputG == 'Y' || inputG == 'y')
						diagnosa = outP[1];
					else
					{
						questionSymptom(jmlPertanyaan, outG[14], inputG);

						if (inputG == 'Y' || inputG == 'y')
							diagnosa = outP[2];
						else
						{
							questionSymptom(jmlPertanyaan, outG[1], inputG);

							if (inputG == 'Y' || inputG == 'y')
							{
								questionSymptom(jmlPertanyaan, outG[3], inputG);

								if (inputG == 'Y' || inputG == 'y')
									diagnosa = outP[3];
								else
								{
									questionSymptom(jmlPertanyaan, outG[4], inputG);

									if (inputG == 'Y' || inputG == 'y')
									{
										questionSymptom(jmlPertanyaan, outG[2], inputG);

										if (inputG == 'Y' || inputG == 'y')
											diagnosa = outP[4];
									}
								}
							}
						}
					}
				}
			}
			else
			{
				questionSymptom(jmlPertanyaan, outG[5], inputG);

				if (inputG == 'Y' || inputG == 'y')
				{
					questionSymptom(jmlPertanyaan, outG[6], inputG);

					if (inputG == 'Y' || inputG == 'y')
						diagnosa = outP[5];
				}
				else
				{
					questionSymptom(jmlPertanyaan, outG[11], inputG);

					if (inputG == 'Y' || inputG == 'y')
					{
						questionSymptom(jmlPertanyaan, outG[16], inputG);

						if (inputG == 'Y' || inputG == 'y')
							diagnosa = outP[8];
					}
					else
					{
						questionSymptom(jmlPertanyaan, outG[9], inputG);

						if (inputG == 'Y' || inputG == 'y')
						{
							questionSymptom(jmlPertanyaan, outG[10], inputG);

							if (inputG == 'Y' || inputG == 'y')
								diagnosa = outP[7];
						}
						else
						{
							questionSymptom(jmlPertanyaan, outG[7], inputG);

							if (inputG == 'Y' || inputG == 'y')
							{
								questionSymptom(jmlPertanyaan, outG[8], inputG);

								if (inputG == 'Y' || inputG == 'y')
									diagnosa = outP[6];
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
					 << hasilDiagnosaText + diagnosa + "\n" + garis;

			// Ulangi?
			cout << "\n"
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
