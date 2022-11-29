#include <iostream>
using namespace std;

struct pendaftar
{
  string nama, nomor, alamat;
  pendaftar *next;
} * queueAwal, *queueAkhir;

struct sembako
{
  string merk;
  sembako *atas, *bawah;
} * stackAtas, *stackBawah;

char loop = 'y';

void buatstack();
bool stackkosong() { return stackBawah == NULL; }
void push(sembako IB);
void pop();
void cetakstack();
int jumlahstack();

void buatqueue();
bool queuekosong() { return queueAwal == NULL; }
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

      cout << "Tambah Sembako: \n";

      cin.ignore();
      cout << "Merk > ";
      getline(cin, temp.merk);

      push(temp);
      break;
    }

    case 2:
    {
      pendaftar temp;

      cout << "Pendaftaran Antrian Sembako: \n";

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
      printf("\nKembali ke menu? (y/n) > ");
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
    cout << "Berhasil ditambahkan! \n";
  }
}

void pop()
{
  if (stackkosong())
  {
    cout << "Sembako masih kosong! \n";
  }
  else
  {
    sembako *hapus;
    hapus = stackAtas;

    cout << "Sembako: " << hapus->merk << "\n";

    stackAtas = stackAtas->bawah;
    stackAtas->atas = NULL;
    free(hapus);
  }
}

void cetakstack()
{
  if (stackkosong())
  {
    cout << "Sembako masih kosong! \n";
  }
  else
  {
    sembako *bantu;
    int no = 1;

    bantu = stackBawah;
    while (bantu != NULL)
    {
      cout << no++ << ". " << bantu->merk << "\n";
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
    jml++;
    bantu = bantu->atas;
  }

  return jml;
}

void buatqueue()
{
  queueAwal = NULL;
  queueAkhir = queueAwal;
}

void enqueue(pendaftar IB)
{
  pendaftar *NQ;

  NQ = new pendaftar;
  *NQ = IB;
  NQ->next = NULL;

  if (queuekosong())
  {
    queueAwal = NQ;
  }
  else
  {
    queueAkhir->next = NQ;
  }

  queueAkhir = NQ;
}

void dequeue()
{
  if (queuekosong())
  {
    cout << "Antrian masih kosong! \n";
  }
  else
  {
    pendaftar *hapus;
    hapus = queueAwal;

    cout << "Nama: " << hapus->nama << "\n";

    queueAwal = queueAwal->next;
    free(hapus);
  }
}

void cetakqueue()
{
  if (queuekosong())
  {
    cout << "Antrian masih kosong! \n";
  }
  else
  {
    pendaftar *bantu;
    int no = 1;

    bantu = queueAwal;
    while (bantu != NULL)
    {
      cout << no++ << ". \n"
           << "Nama: " << bantu->nama << "\n"
           << "No. : " << bantu->nomor << "\n"
           << "Alamat : " << bantu->alamat << "\n\n";
      bantu = bantu->next;
    }
  }
}
