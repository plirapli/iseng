/*Stack Menggunakan Record*/
#include <iostream>
#include <malloc.h>

using std::cout;
using std::endl;

const int max = 50;

struct typeStack
{
  int top;
  int elemen[max];
} Stack;

void buat();
void cetak();
void push(int newData);
void pop();

// Cek kondisi stack
int isEmpty() { return Stack.top == -1; }
int isFull() { return Stack.top == max; }

int main()
{
  buat();
  push(10);
  push(76);
  push(12);
  push(1);
  cetak();

  cout << "\n";

  pop();
  pop();
  pop();
  cetak();
}

void buat()
{
  Stack.top = -1;
}

void push(int newData)
{
  if (isFull())
    cout << "Stack Overflow! \n";
  else
  {
    Stack.top++;
    Stack.elemen[Stack.top] = newData;
  };
}

void pop()
{
  int IP;
  if (isEmpty())
    cout << "Stack Underflow! \n";
  else
  {
    IP = Stack.elemen[Stack.top];
    Stack.top--;
  };
}

void cetak()
{
  for (int i = 0; i <= Stack.top; i++)
    cout << " " << Stack.elemen[i] << "\n";
}
