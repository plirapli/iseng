#include <iostream>
using namespace std;

struct pendaftar
{
  string nama, nomor, alamat;
  pendaftar *next;
} * antrianDepan, *antrianBelakang;

struct sembako
{
  string merk;
  sembako *atas, *bawah;
} * stackAtas, *stackBawah;

char loop = 'y';

void buatstack();
bool stackkosong();
void push(sembako IB);
void pop();
void cetakstack();
int jumlahstack();

void buatqueue();
bool queuekosong();
void enqueue(pendaftar IB);
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
    {
      sembako temp;

      cout << "Tambah Sembako \n";

      cin.ignore();
      cout << "Merk > ";
      getline(cin, temp.merk);
      push(temp);

      break;
    }

    case 2:
    {
      pendaftar temp;

      cout << "Pendaftaran Sembako \n";

      cin.ignore();
      cout << "Nama > ";
      getline(cin, temp.nama);

      cout << "Nomor > ";
      cin >> temp.nomor;
      cin.ignore();

      cout << "Alamat > ";
      getline(cin, temp.alamat);

      enqueue(temp);
      break;
    }

    case 3:
      dequeue();
      pop();
      break;

    case 4:
      cetakstack();
      break;

    case 5:
      cetakqueue();
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
      printf("Kembali ke menu? (y/n) ");
      cin >> loop;
    }
  }

  return 0;
}

void buatstack()
{
  stackAtas = NULL;
  stackBawah = stackAtas;
}

bool stackkosong() { return stackBawah == NULL; }

void push(sembako IB)
{
  sembako *NS;

  NS = new sembako;
  *NS = IB;

  NS->atas = NULL;
  NS->bawah = NULL;

  if (stackkosong())
  {
    stackAtas = NS;
    stackBawah = NS;
  }
  else
  {
    stackAtas->atas = NS;
    NS->bawah = stackAtas;
    stackAtas = NS;
  }
}

void pop()
{
  sembako *hapus;

  if (stackkosong())
    cout << "Stack kosong! \n";
  else
  {
    hapus = stackAtas;

    cout << "Sembako: " << hapus->merk << "\n";

    stackAtas = stackAtas->bawah;
    stackAtas->atas = NULL;
    delete hapus;
  }
}

void cetakstack()
{
  if (stackkosong())
  {
    cout << "Sembako belum ada! \n";
  }
  else
  {
    sembako *bantu;
    int no = 1;

    cout << "Dari tumpukan paling bawah: \n";
    bantu = stackBawah;
    while (bantu != NULL)
    {
      cout << no++ << ". " << bantu->merk << '\n';
      bantu = bantu->atas;
    }
  }
}

int jumlahstack()
{
  sembako *bantu;
  int jml = 0;

  bantu = stackBawah;
  while (bantu != NULL)
  {
    bantu = bantu->atas;
    jml++;
  }

  return jml;
}

void buatqueue()
{
  antrianDepan = NULL;
  antrianBelakang = antrianDepan;
}

bool queuekosong() { return antrianDepan == NULL; }

void enqueue(pendaftar IB)
{
  pendaftar *NB;

  NB = new pendaftar;
  *NB = IB;

  if (queuekosong())
    antrianDepan = NB;
  else
    antrianBelakang->next = NB;

  // Nandain antrian belakang
  antrianBelakang = NB;
  antrianBelakang->next = NULL;
}

void dequeue()
{
  pendaftar *hapus;

  if (queuekosong())
    cout << "Pendaftar masih kosong! \n";
  else
  {
    hapus = antrianDepan;

    // Menampilkan Data yang mau dihapus
    cout << "Nama: " << hapus->nama << "\n";

    antrianDepan = hapus->next;
    free(hapus);
  }
}

void cetakqueue()
{
  if (queuekosong())
  {
    cout << "Pendaftar masih kosong! \n";
  }
  else
  {
    pendaftar *bantu;
    int no = 1;

    bantu = antrianDepan;
    do
    {
      cout << no++ << ". "
           << bantu->nama << ", "
           << bantu->alamat << ", "
           << bantu->nomor << "\n";
      bantu = bantu->next;
    } while (bantu != NULL);
  }
}
