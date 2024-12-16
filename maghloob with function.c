#include <stdio.h>
int maghloob(int n)
{
   int r, sum=0;

   while(n>0)
   {
      r=n%10;
      sum=r+(sum*10);
      n=n/10;
   }
   return sum;
}

int main()
{
  int n, sum=0;
  printf("please enter a number: ");
  scanf("%d" , &n);
  printf("%d", maghloob(n));

return 0;
}