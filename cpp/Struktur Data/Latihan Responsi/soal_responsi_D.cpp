#include <iostream>

using namespace std;

struct info
{
	string pengirim, jenisBarang, tujuan;
};

struct antrian
{
	info barang;
	antrian *next;
} * queueDepan, *queueBelakang;

struct tumpukan
{
	info barang;
	tumpukan *atas, *bawah;
} * stackAtas, *stackBawah;

struct linkedList
{
	info barang;
	linkedList *next;
} * kepala, *ekor;

const int maksWadah = 3;
int jmlBarangWadah = 0;

void buatQueue();
bool cekAntrian() { return queueDepan == NULL; }
void enqueue(info IB);
info dequeue();
void cetakAntrian();

void buatTumpukan();
bool cekTumpukan() { return stackBawah == NULL; }
void push(info IB);
void pop();
void cetakTumpukan();

void buatLinkedList();
bool cekLinkedList() { return kepala == NULL; }
void sisip(info IB);
void cetakLinkedList();

int main()
{
	char pilih, loop = 'y';

	buatQueue();
	buatTumpukan();

	while (loop == 'y' || loop == 'Y')
	{
		system("CLS");
		cout << "MENU \n"
				 << "--------------------------------- \n"
				 << "[1] Input Barang ke Antrian \n"
				 << "[2] Input Barang ke Wadah \n"
				 << "[3] Kirim Barang \n"
				 << "[4] Lihat Antrian \n"
				 << "[5] Lihat Barang di Wadah \n"
				 << "[6] Riwayat Barang \n"
				 << "[...] Keluar \n"
				 << "Pilih > ";
		cin >> pilih;

		switch (pilih)
		{
		case '1':
		{
			info temp;

			cout << "Input Barang ke Antrian \n";
			cin.ignore();
			cout << "Pengirim > ";
			getline(cin, temp.pengirim);

			cout << "Jenis Barang > ";
			getline(cin, temp.jenisBarang);

			cout << "Tujuan > ";
			getline(cin, temp.tujuan);

			enqueue(temp);
			break;
		}

		case '2':
		{
			cout << "Masukkan barang ke Wadah \n";
			if (jmlBarangWadah < maksWadah)
			{
				if (cekAntrian())
				{
					cout << "Barang di antrian masih kosong! \n\n";
				}
				else
				{
					info barangPindahan = dequeue();
					push(barangPindahan);
				}
			}
			else
			{
				cout << "Wadah telah memenuhi kapasitas! \n";
			}
			break;
		}

		case '3':
		{
			cout << "Kirim Barang \n";

			for (int i = 0; i < jmlBarangWadah; i++)
				pop();

			break;
		}

		case '4':
			cout << "Lihat Antrian \n";
			cetakAntrian();
			break;

		case '5':
			cout << "Lihat Barang di Wadah \n";
			cetakTumpukan();
			break;

		case '6':
			cout << "Riwayat Barang \n";
			cetakLinkedList();
			break;

		default:
			loop = 'n';
			break;
		}
		if (loop == 'y' || loop == 'Y')
		{
			cout << "Kembali ke menu? (y/n) > ";
			cin >> loop;
		}
	}

	return 0;
}

void buatQueue()
{
	queueDepan = NULL;
	queueBelakang = queueDepan;
}

void enqueue(info IB)
{
	antrian *NQ;

	NQ = new antrian;
	NQ->barang = IB;
	NQ->next = NULL;

	if (cekAntrian())
	{
		queueDepan = NQ;
	}
	else
	{
		queueBelakang->next = NQ;
	}
	queueBelakang = NQ;
}

info dequeue()
{
	antrian *hapus;
	info barangPindahan;

	hapus = queueDepan;
	barangPindahan = hapus->barang;

	cout << "Barang yang dipindahkan ke Wadah: \n"
			 << "Pengirim: " << hapus->barang.pengirim << "\n"
			 << "Jenis Barang: " << hapus->barang.jenisBarang << "\n"
			 << "Tujuan: " << hapus->barang.tujuan << "\n\n";

	queueDepan = queueDepan->next;
	delete hapus;

	return barangPindahan;
}

void cetakAntrian()
{
	antrian *bantu;
	int no = 1;

	bantu = queueDepan;
	while (bantu != NULL)
	{
		cout << no++ << ". \n"
				 << "Pengirim: " << bantu->barang.pengirim << "\n"
				 << "Jenis Barang: " << bantu->barang.jenisBarang << "\n"
				 << "Tujuan: " << bantu->barang.tujuan << "\n\n";
		bantu = bantu->next;
	}
}

void buatTumpukan()
{
	stackBawah = NULL;
	stackAtas = stackBawah;
}

void push(info IB)
{
	tumpukan *NS;
	NS = new tumpukan;

	NS->barang = IB;
	NS->atas = NULL;
	NS->bawah = NULL;

	if (cekTumpukan())
	{
		stackBawah = NS;
	}
	else
	{
		stackAtas->atas = NS;
		NS->bawah = stackAtas;
	}

	stackAtas = NS;
	jmlBarangWadah++;
}

void pop()
{
	if (cekTumpukan())
	{
		cout << "Wadah masih kosong! \n";
	}
	else
	{
		tumpukan *bantu, *hapus;
		info barangPindahan;

		bantu = stackBawah;
		hapus = stackAtas;

		barangPindahan = hapus->barang;
		sisip(barangPindahan);

		if (hapus == stackBawah)
			stackAtas = NULL;
		else
		{
			while (bantu->atas->atas != NULL)
				bantu = bantu->atas;

			stackAtas = bantu;
			stackAtas->atas = NULL;
		}

		delete hapus;
	}
}

void cetakTumpukan()
{
	tumpukan *bantu;
	int no = 1;

	bantu = stackBawah;
	while (bantu != NULL)
	{
		cout << no++ << ". \n"
				 << "Pengirim: " << bantu->barang.pengirim << "\n"
				 << "Jenis Barang: " << bantu->barang.jenisBarang << "\n"
				 << "Tujuan: " << bantu->barang.tujuan << "\n\n";
		bantu = bantu->atas;
	}
}

void buatLinkedList()
{
	kepala = NULL;
	ekor = NULL;
}

void sisip(info IB)
{
	linkedList *NB;

	NB = new linkedList;
	NB->barang = IB;
	NB->next = NULL;

	if (cekLinkedList())
	{
		kepala = NB;
	}
	else
	{
		ekor->next = NB;
	}
	ekor = NB;
}

void cetakLinkedList()
{
	linkedList *bantu;
	int no = 1;

	bantu = kepala;
	while (bantu != NULL)
	{
		cout << no++ << ". \n"
				 << "Pengirim: " << bantu->barang.pengirim << "\n"
				 << "Jenis Barang: " << bantu->barang.jenisBarang << "\n"
				 << "Tujuan: " << bantu->barang.tujuan << "\n\n";
		bantu = bantu->next;
	}
}
