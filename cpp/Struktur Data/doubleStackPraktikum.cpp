/*Program Stack menggunakan pointer*/
#include <iostream>

using std::cout;

typedef int typeinfo;
struct Stack
{
	typeinfo info;
	Stack *kiri, *kanan;
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
	Stack *NS;

	NS = new Stack;
	NS = NULL;

	stackAwal = NS;
	stackAkhir = NS;
}

void push(typeinfo newInfo)
{
	Stack *NS;

	NS = new Stack;
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
	Stack *hapus;

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
	Stack *bantu;

	bantu = stackAwal;
	while (bantu != NULL)
	{
		cout << " " << bantu->info << '\n';
		bantu = bantu->kiri;
	}
}
