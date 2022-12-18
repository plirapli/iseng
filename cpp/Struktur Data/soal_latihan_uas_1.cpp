#include <stdio.h>
#include <malloc.h>

using namespace std;

typedef struct typenode *typeptr;
struct typenode
{
  int info;
  typeptr next;
};

int main()
{
  int n = 50;
  typeptr p, q, r;

  p = (typenode *)malloc(sizeof(typenode));
  q = (typenode *)malloc(sizeof(typenode));
  r = (typenode *)malloc(sizeof(typenode));

  p->info = n;
  r->next = p;
  p = q;
  q->info = 30;
  p->info = 100 + r->next->info;
  r->info = q->info;
  q = r->next;
  q->next = p;
  p->next = r->next;
  n = q->next->info + q->info - n;

  printf("n = %d\n", n);
  printf("p->next->next->info = %d\n", p->next->next->info);
  printf("q->next->info = %d\n", q->next->info);
  printf("r->info = %d", r->info);

  return 0;
}