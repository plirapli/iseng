#include <iostream>
#include <stdlib.h>

using namespace std;

void latihanSatu();
void latihanDua();

int main()
{
	latihanSatu();
	cout << "\n";
	latihanDua();

	return 0;
}

void latihanSatu()
{
	int a = 3, b, *p, *q, *r, **x;

	p = (int *)malloc(sizeof(int)); // Menunjuk int kosong (ex: y)
	r = (int *)malloc(sizeof(int)); // Menunjuk int kosong juga (ex: z)

	q = &b;			 // q menunjuk alamat b
	*q = a;			 // nilai int yang ditunjuk q = 3 (b = 3)
	x = &p;			 // x menunjuk alamat p
	*r = a - 1;	 // nilai int yang ditunjuk r = 3 - 1 = 2
	q = p;			 // q menunjuk alamat kosong yang sama dengan p (y)
	p = r;			 // p menunjuk alamat yang sama dengan r (z = 2)
	*q = *r;		 // nilai int yang ditunjuk q sama dengan nilai int yang ditunjuk r (y = 2)
	*r = *p + a; // nilai int yang ditunjuk r adalah nilai int p + a (z = 3 + 2 = 5)
	a = a + 2;	 // a = 5
	x = &r;			 // x menunjuk alamat r (nilai int = 5)

	cout << a << " " << b << " " << *p << " " << *q << " " << *r << " " << **x << "\n";
	// Expected output = 5 3 5 2 5 5
}

void latihanDua()
{
	int e[3] = {10, 20, 30}, f = 40;
	int *a, *b, *c, **d;

	a = e;	// a = alamat dari e[0] (e[0] = 10)
	b = &f; // b = alamat dari f (f = 40)
	c = &f; // c = alamat dari f (f = 40)
	d = &c; // d = alamat dari c (*c = f = 40)

	a = &e[1];			 // a = alamat dari e[1] (e[1] = 20)
	c = a;					 // c menunjuk alamat yg sama dengan a (e[1] = 20)
	*a = *c + f;		 // nilai int yang ditunjuk a = 20 + 40 (e[1] = 60)
	d = &a;					 // d menunjuk alamat a
	a = b;					 // a menunjuk alamat yang sama dengan b (f = 40)
	b = e;					 // b = alamat dari e[0] (e[0] = 10)
	e[0] = *(b + 1); // nilai e[0] = 60
	*(b + 2) = **d;	 // nilai e[2] = 40

	cout << e[0] << " " << e[1] << " " << e[2] << " "
			 << *a << " " << *b << " " << *c << " "
			 << **d << " " << f << "\n";

	// Expected output = 60 60 40 40 60 60 40 40
}