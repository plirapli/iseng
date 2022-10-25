#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

typedef struct typenode *typeptr;
struct typenode
{
  int info;
  typeptr next;
};

int main()
{
  int a = 50;
  typeptr p, q, r;
  p = (typenode *)malloc(sizeof(typenode));
  q = (typenode *)malloc(sizeof(typenode));
  r = (typenode *)malloc(sizeof(typenode));

  // Baris 1
  p->info = a;
  r->next = p;
  p = q;
  q->info = 20;

  // Baris 2
  p->info = 2 * r->next->info - 5;

  // Baris 3
  r->info = q->info;
  q = r->next;
  q->next = p;

  // Baris 4
  p->next = r->next;
  a = q->next->info + q->info - a;

  printf("p->next->next->info = %d\n", p->next->next->info);
  printf("q->next->info = %d\n", q->next->info);
  printf("r->info = %d\n", r->info);
  printf("a = %d", a);

  return 0;
}