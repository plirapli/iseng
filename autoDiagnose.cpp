#include <iostream>

using namespace std;

void questionSymptom(int &outJmlPertanyaan, string symptom, char &outInput);

int main()
{
	int jmlPertanyaan = 0;
	char inputG[17];
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
					 "[ P07 ] Milia", "[ P08 ] Acne rosacea"},
			diagnosa = outP[0];

	cout << garis << "\n";
	cout << "No. Diagnosa \t: ";
	getline(cin, nim);
	cout << "Tgl. Diagnosa \t: ";
	getline(cin, tgl);
	cout << "Nama Pasien \t: ";
	getline(cin, nama);
	cout << garis << "\n\n";

	string hasilDiagnosaText = "HASIL DIAGNOSA PENYAKIT JERAWAT (" + nama + "): \n";

	cout << "PERTANYAAN GEJALA :";
	questionSymptom(jmlPertanyaan, outG[15], inputG[15]);

	if (inputG[15] == 'Y' || inputG[15] == 'y')
	{
		questionSymptom(jmlPertanyaan, outG[12], inputG[12]);

		if (inputG[12] == 'Y' || inputG[12] == 'y')
		{
			questionSymptom(jmlPertanyaan, outG[13], inputG[13]);

			if (inputG[13] == 'Y' || inputG[13] == 'y')
				diagnosa = outP[1];
			else
			{
				questionSymptom(jmlPertanyaan, outG[14], inputG[14]);

				if (inputG[14] == 'Y' || inputG[14] == 'y')
					diagnosa = outP[2];
				else
				{
					questionSymptom(jmlPertanyaan, outG[1], inputG[1]);

					if (inputG[1] == 'Y' || inputG[1] == 'y')
					{
						questionSymptom(jmlPertanyaan, outG[3], inputG[3]);

						if (inputG[3] == 'Y' || inputG[3] == 'y')
							diagnosa = outP[3];
						else
						{
							questionSymptom(jmlPertanyaan, outG[4], inputG[4]);

							if (inputG[4] == 'Y' || inputG[4] == 'y')
							{
								questionSymptom(jmlPertanyaan, outG[2], inputG[2]);

								if (inputG[2] == 'Y' || inputG[2] == 'y')
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
		questionSymptom(jmlPertanyaan, outG[5], inputG[5]);

		if (inputG[5] == 'Y' || inputG[5] == 'y')
		{
			questionSymptom(jmlPertanyaan, outG[6], inputG[6]);

			if (inputG[6] == 'Y' || inputG[6] == 'y')
				diagnosa = outP[5];
		}
		else
		{
			questionSymptom(jmlPertanyaan, outG[11], inputG[11]);

			if (inputG[11] == 'Y' || inputG[11] == 'y')
			{
				questionSymptom(jmlPertanyaan, outG[16], inputG[16]);

				if (inputG[6] == 'Y' || inputG[6] == 'y')
					diagnosa = outP[8];
			}
			else
			{
				questionSymptom(jmlPertanyaan, outG[9], inputG[9]);

				if (inputG[9] == 'Y' || inputG[9] == 'y')
				{
					questionSymptom(jmlPertanyaan, outG[10], inputG[10]);

					if (inputG[10] == 'Y' || inputG[10] == 'y')
						diagnosa = outP[7];
				}
				else
				{
					questionSymptom(jmlPertanyaan, outG[7], inputG[7]);

					if (inputG[7] == 'Y' || inputG[7] == 'y')
					{
						questionSymptom(jmlPertanyaan, outG[8], inputG[8]);

						if (inputG[8] == 'Y' || inputG[8] == 'y')
							diagnosa = outP[6];
					}
				}
			}
		}
	}

	cout << "\n Jumlah Pertanyaan Gejala = " << jmlPertanyaan
			 << "\n\n" + garis + "\n\n" + hasilDiagnosaText + diagnosa + "\n\n" + garis;

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
