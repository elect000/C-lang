#include <stdio.h>
void func(int n, int length);
int len(int* n);

int main(void)
{
  int n, tmp;

  printf("Input number ");
  scanf("%d", &n);
  func(n , len(&n));
  printf("\n");
  return 0;
}

int len(int* n)
{
  int tmp = *n;
  int i = 0;
  while((tmp / 10) == 0) {
    ++i;
  }
  return i;
}

void func(int n, int length)
{
  if (n == 0){
    return;
  }
  printf("%d", n % 10);
  func(n / 10, --length);
  return;
}
