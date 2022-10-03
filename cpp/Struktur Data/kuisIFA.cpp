#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

struct menu
{
  char nama[30];
  int stok;
  float harga;

  menu *next;
} * kepala, *ekor;

char loop = 'y';
int pilih, banyak;

void buatlistbaru();
void sisipnode(menu IB); // parameter bebas mau input pake struct apa 1/1, misal pakai struct sisipnode(barang IB)
void hapusnode(char *IH);
void editbarang(char *CB);
void bacamaju();
bool listkosong();

int main()
{
  char IH[30];

  buatlistbaru();
  while (loop == 'y' || loop == 'Y')
  {
    system("cls");
    puts("Menu");
    puts("1. Input Menu");
    puts("2. Cetak Menu");
    puts("3. Edit Menu");
    puts("4. Hapus Menu");
    printf("Pilih : ");
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      menu IB;
      system("cls");
      printf("Berapa banyak data? ");
      cin >> banyak;

      for (int i = 0; i < banyak; i++)
      {
        cin.ignore();
        printf("Nama Menu  : ");
        cin.getline(IB.nama, 30);
        printf("Harga Menu : ");
        cin >> IB.harga;
        printf("Stok Menu  : ");
        cin >> IB.stok;

        sisipnode(IB);
        cout << endl;
      }

      break;

    case 2:
      system("cls");
      printf("Cetak Menu\n");
      bacamaju();
      break;

    case 3:
      system("cls");
      printf("Edit Menu");
      bacamaju();
      if (!listkosong())
      {
        printf("===========\n");
        printf("Cari nama barang = ");
        cin.ignore();
        cin.getline(IH, 30);
        editbarang(IH);
      }
      break;

    case 4:
      system("cls");
      printf("Hapus Barang\n");
      bacamaju();
      if (!listkosong())
      {
        printf("===========\n");
        printf("Cari nama barang = ");
        cin.ignore();
        cin.getline(IH, 30);
        hapusnode(IH);
      }
      break;

    default:
      break;
    }

    printf("kembali ke menu ? (y/n) ");
    cin >> loop;
  }
  return 0;
}

void buatlistbaru()
{
  // POIN 10
  kepala = new menu;
  ekor = new menu;

  kepala->stok = -9999;
  kepala->next = ekor;

  ekor->stok = 9999;
  ekor->next = NULL;
}

bool listkosong()
{ /* POIN 5 */
  return kepala->next == ekor;
}

void sisipnode(menu IB)
{
  // POIN 25
  menu *NB, *bantu;

  NB = new menu;
  strcpy(NB->nama, IB.nama);
  NB->harga = IB.harga;
  NB->stok = IB.stok;
  NB->next = NULL;

  bantu = kepala;
  while (IB.stok > bantu->next->stok)
    bantu = bantu->next;

  NB->next = bantu->next;
  bantu->next = NB;
}
void hapusnode(char *IH)
{
  /* POIN 25
   * Lengkapi kodingan fn hapusnode() */
  menu *hapus, *bantu;

  if (listkosong())
  {
    cout << "List masih kosong \n";
  }
  else
  {
    bantu = kepala;
    while (bantu->next != ekor && strcmp(IH, bantu->next->nama) != 0)
      bantu = bantu->next;

    if (strcmp(IH, bantu->next->nama) == 0)
    {
      hapus = bantu->next;
      bantu->next = hapus->next;
      delete hapus;
    }
    else
      cout << "Node tidak ditemukan! \n";
  }
}

void bacamaju()
{
  // POIN 15
  printf("%-20s %-5s %s \n", "Nama Barang", "Stok", "Harga Barang");
  for (int i = 0; i < 75; i++)
  {
    cout << "-";
  }
  cout << endl;

  if (listkosong())
    printf("   Data Barang Tidak Ada\n");
  else
  {
    menu *bantu;
    bantu = kepala->next;
    while (bantu != ekor)
    {
      printf("%-20s %-5d Rp.%.1f \n", bantu->nama, bantu->stok, bantu->harga);
      bantu = bantu->next;
    }
  }
  for (int i = 0; i < 75; i++)
  {
    cout << "-";
  }
  cout << endl;
}

void editbarang(char *CB)
{
  // POIN 20
  menu *hapus, *bantu;

  if (listkosong())
    cout << "List masih kosong";
  else
  {
    bantu = kepala;
    while (bantu != ekor && strcmp(CB, bantu->next->nama) != 0)
      bantu = bantu->next;

    if (strcmp(CB, bantu->next->nama) == 0)
    {
      // Nambah node baru
      menu ganti;

      cout << "Edit barang " << bantu->next->nama << "\n";
      cout << "Nama barang = ";

      cin.getline(ganti.nama, 30);
      cout << "Harga barang = ";
      cin >> ganti.harga;
      cout << "Stok barang = ";
      cin >> ganti.stok;

      // Hapus node lama
      hapus = bantu->next;
      bantu->next = hapus->next;
      delete hapus;

      sisipnode(ganti);
    }
    else
      cout << "Node tidak ditemukan!\n";
  }
}
