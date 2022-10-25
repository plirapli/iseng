/*Program Stack menggunakan pointer*/
#include <iostream>

using std::cout;

typedef int typeinfo;
struct typestack
{
	typeinfo info;
	typestack *kiri, *kanan;
} * stackAwal, *stackAkhir;

void buat();
void push(typeinfo newInfo);
void pop();
void cetak();

// Cek kondisi stack
int isEmpty() { return stackAwal == NULL; }

int main()
{
	buat();
	push(25);
	push(15);
	push(20);
	push(100);
	cetak();

	cout << "\n";

	pop();
	cetak();
}

void buat()
{
	typestack *NS;

	NS = new typestack;
	NS = NULL;

	stackAwal = NS;
	stackAkhir = NS;
}

void push(typeinfo newInfo)
{
	typestack *NS;

	NS = new typestack;
	NS->info = newInfo;
	NS->kiri = NULL;
	NS->kanan = NULL;

	if (stackAwal == NULL)
	{
		stackAwal = NS;
		stackAkhir = NS;
	}
	else
	{
		stackAwal->kanan = NS;
		NS->kiri = stackAwal;
		stackAwal = NS;
	}
}

void pop()
{
	typestack *hapus;

	if (isEmpty())
		cout << "Stack kosong! \n";
	else
	{
		hapus = stackAwal;
		stackAwal = stackAwal->kiri;
		stackAwal->kanan = NULL;
		delete hapus;
	}
}

void cetak()
{
	typestack *bantu;

	bantu = stackAwal;
	while (bantu != NULL)
	{
		cout << " " << bantu->info << '\n';
		bantu = bantu->kiri;
	}
}
