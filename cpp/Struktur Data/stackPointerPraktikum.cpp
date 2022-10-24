/*Program Stack menggunakan pointer*/
#include <iostream>

using std::cout;

typedef int typeinfo;
struct typestack
{
  typeinfo info;
  typestack *next;
} * stack, *awal;

void buatstack();
void push(typeinfo IB);
void pop();
void cetakstack();

// Cek kondisi stack
int isEmpty() { return awal == NULL; }

int main()
{
  buatstack();
  push(25);
  push(15);
  push(20);
  push(100);
  cetakstack();

  cout << "\n";

  pop();
  cetakstack();

  return 0;
}

void buatstack()
{
  typestack *NS;

  NS = new typestack;
  NS = NULL;
  awal = NS;
}

void push(typeinfo IB)
{
  typestack *NS;

  NS = new typestack;
  NS->info = IB;

  if (awal == NULL)
    awal = NS;
  else
    stack->next = NS;

  stack = NS;
  stack->next = NULL;
}

void pop()
{
  typestack *hapus, *bantu;

  if (isEmpty())
    cout << "Stack kosong! \n";
  else
  {
    bantu = awal;
    hapus = stack;

    if (hapus == awal)
      awal = NULL;
    else
    {
      while (bantu->next->next != NULL)
        bantu = bantu->next;

      stack = bantu;
      stack->next = NULL;
    }

    delete hapus;
  }
}

void cetakstack()
{
  typestack *bantu;

  bantu = awal;
  while (bantu != NULL)
  {
    cout << " " << bantu->info << '\n';
    bantu = bantu->next;
  }
}