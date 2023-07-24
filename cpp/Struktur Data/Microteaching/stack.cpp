/*Program Stack menggunakan pointer*/
#include <iostream>

using namespace std;

struct StackNode
{
  int info;
  StackNode *next;
} *stack, *awal;

void buat()
{
  StackNode *newStack;

  newStack = new StackNode;
  newStack = NULL;
  awal = newStack;
}

void push(int infoBaru)
{
  StackNode *newStack;

  newStack = new StackNode;
  newStack->info = infoBaru;

  if (awal == NULL)
    awal = newStack;
  else
    stack->next = newStack;

  stack = newStack;
  stack->next = NULL;
}

void cetak()
{
  StackNode *bantu;

  bantu = awal;
  while (bantu != NULL)
  {
    cout << bantu->info << '\n';
    bantu = bantu->next;
  }
}

int main()
{
  buat();
  push(25);
  push(15);
  push(20);
  push(100);
  cetak();

  return 0;
}