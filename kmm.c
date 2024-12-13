#include<stdio.h>
int bmm(int a, int b)
{ 
  int t;
  while (b!=0)
  {
    t=b;
    b=a%b;
    a=t;
  }
  return a;
  
  if(b==0)
  return a;
}

int kmm(int a, int b)
{
  return (a*b)/bmm(a,b);
} 

int main()
{ 
  int a, b;
  printf("please enter 2 numbers:");
  scanf("%d %d", &a, &b);  
  printf("\nkmm of %d and %d is: %d", a, b, kmm(a,b));
  
  return 0;
}  