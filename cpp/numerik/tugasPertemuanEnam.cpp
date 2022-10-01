#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int iterasiMaks = 25, indexHasil = 0;
	double batasToleransi = 0.00001;
	double x[iterasiMaks], fx[iterasiMaks], gx[iterasiMaks], error = 0;

	// Memasukkan nilai x ke-0
	x[0] = 4;

	cout << "Persamaan \t\t: f(x) = x^2 - 4x - 21 \n"
			 << "Metode \t\t\t: Titik Tetap \n"
			 << "x ke-0 \t\t\t: " << x[0] << "\n"
			 << "Iterasi Maks. \t\t: " << iterasiMaks << "\n"
			 << "Toleransi Error \t: " << batasToleransi << "\n\n"
			 << "Tabel Iterasi : \n"
			 << "+--------------------------------------------------------------------------------------------+ \n"
			 << "| Iterasi |        xn        |       g(xn)      |         f(xn)        |         Error       | \n"
			 << "+--------------------------------------------------------------------------------------------+ \n";

	for (int n = 0; n <= 25; n++)
	{
		// Memasukkan variabel xn di fungsi f(x) dan g(x)
		fx[n] = (x[n] * x[n]) - (4 * x[n]) - 21;
		gx[n] = 21 / (x[n] - 4);

		// Menghitung error dengan rumus | g(xn) - xn |
		error = gx[n] - x[n];
		error = error < 0 ? -1 * error : error;

		// Menampilkan Tabel
		cout << "| " << left << setw(8) << n << "| ";									// Iterasi ke-n
		cout << left << setw(17) << setprecision(14) << x[n] << "| "; // Variabel x ke-n
		cout << left << setw(17) << gx[n] << "| ";										// Fungsi f(x) dengan variabel x ke-n
		cout << left << setw(21) << fx[n] << "| ";										// Fungsi g(x) dengan variabel x ke-n
		cout << left << setw(20) << error << "| \n";									// Error

		// Nilai dari variabel x ke-(n+1) merupakan nilai dari hasil fungsi g(x)
		x[n + 1] = gx[n];

		// Menentukan index dari akar persamaan yang sesuai dengan batas toleransi
		if (error < batasToleransi && indexHasil == 0)
			indexHasil = n;
	}
	cout << "+--------------------------------------------------------------------------------------------+ \n";

	cout << "Akar persamaan dengan  toleransi error " << batasToleransi << ": " << x[indexHasil];

	return 0;
}