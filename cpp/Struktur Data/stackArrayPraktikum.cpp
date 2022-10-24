/*Stack menggunakan array*/
#include <iostream>

using std::cout;
using std::endl;

const int max = 50; // Jumlah data yang dapat disimpan di array
int top = 0;        // Buat nyimpen index tumpukan paling atas atau jumlah datanya juga bisa
int stack[max];     // Array sebagai media penyimpanan

void buat();
void push(int newData); // Menambah data ke tumpukan paling atas
void pop();             // Mengambil (menghapus data yang terakhir dipush)
void cetak();

// Cek kondisi stack
int isEmpty() { return top == 0; }
int isFull() { return top == max; }

int main()
{
  buat();
  push(10);
  push(76);
  push(12);
  push(21);
  cetak();

  cout << "\n\n";

  pop();
  pop();
  pop();
  cetak();
}

void buat()
{
  stack[top] = 0; // Stack index ke-0 buat nyimpen jumlah data (info)
}

void push(int newData)
{
  if (isFull())
    cout << "Stack Overflow\n";
  else
  {
    top++;
    stack[top] = newData;
    stack[0] = top;
  }
}
void pop()
{
  int IP;
  if (isEmpty())
    cout << "Stack Underflow\n";
  else
  {
    IP = stack[top];
    top--;
    stack[0] = top;
  }
}

void cetak()
{
  cout << "Top: " << top << "\n";
  for (int i = 1; i <= top; i++)
    cout << stack[i] << endl;
}
