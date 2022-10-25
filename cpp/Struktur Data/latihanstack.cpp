/*Program Stack menggunakan pointer*/
#include <iostream>
#include <malloc.h>

using std::cout;

typedef int typeinfo;
struct typestack
{
	typeinfo info;
	typestack *next, *kiri, *kanan;
} * stackAwal, *stackAkhir;

void buatstack();
void push(typeinfo IB);
void pop();
void cetakstack();

// Cek kondisi stack
int isEmpty() { return stackAwal == NULL; }

int main()
{
	buatstack();
	push(25);
	push(15);
	push(20);
	push(100);
	cetakstack();

	cout << " \n\n";

	pop();
	cetakstack();
}

void buatstack()
{
	typestack *NS;

	NS = new typestack;
	NS = NULL;

	stackAwal = NS;
	stackAkhir = NS;
}

void push(typeinfo IB)
{
	typestack *NS;

	NS = new typestack;
	NS->info = IB;
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

void cetakstack()
{
	typestack *bantu;

	bantu = stackAwal;
	while (bantu != NULL)
	{
		cout << " " << bantu->info << '\n';
		bantu = bantu->kiri;
	}
}
