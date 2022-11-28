#include <iostream>
#include <malloc.h>
using namespace std;

struct pendaftar
{
    char nama[30], nomor[20], alamat[50];
};

struct sembako
{
    char merk[30];
};

char loop = 'y';

void buatstack();
bool stackkosong();
void push();
void pop();
void cetakstack();
int jumlahstack();

void buatqueue();
bool queuekosong();
void enqueue();
void dequeue();
void cetakqueue();

int main()
{
    buatqueue();

    int pilih;

    while (loop == 'y' || loop == 'Y')
    {
        system("cls");
        printf("Jumlah sembako = %d\n", jumlahstack());
        printf(" ==== MENU PROGRAM ==== \n");
        printf(" 1. Tambah Sembako\n");
        printf(" 2. Pendaftaran Sembako\n");
        printf(" 3. Ambil Sembako\n");
        printf(" 4. Lihat Sembako\n");
        printf(" 5. Lihat Antrian\n");
        printf(" 6. Keluar\n");
        printf("Pilih = ");
        cin >> pilih;

        switch (pilih)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
            loop = 'n';
            break;

        default:
            printf(" PILIHAN TIDAK DITEMUKAN\n");
            break;
        }

        if (loop == 'y' || loop == 'Y')
        {
            printf(" Kembali ke menu? (y/n) ");
            cin >> loop;
        }
    }

    return 0;
}

void buatstack()
{

}

bool stackkosong()
{

    return false;
}

void push()
{

}

void pop()
{

}

void cetakstack()
{

}

int jumlahstack()
{
    return 0;
}

void buatqueue()
{

}

bool queuekosong()
{

    return false;
}

void enqueue()
{

}

void dequeue()
{

}

void cetakqueue()
{

}
