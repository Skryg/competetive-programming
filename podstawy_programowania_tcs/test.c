#include <stdio.h>

int main()
{
  char dupa[]="9321321 2193129\n1239 32193";
  int n;
   scanf("%d%*[^\n]\n", &n);
  printf("%d\n",n);
  scanf("%d", &n);
  printf("%d\n",n);
  return 0;
}