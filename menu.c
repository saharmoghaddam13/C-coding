#include <stdio.h>

int main() {
    int option;
    float n1, n2, answer;

    while (1)
    {
       printf("\nmenu:\n");
       printf("1-add two numbers:\n");
       printf("2-subtracting two numbers:\n");
       printf("3-multiplication two numbers:\n");
       printf("4-division two numbers:\n");
       printf("5-exit:\n");
       printf("enter your option: ");
       scanf("%d", &option);


       if (option==1) 
       {
          printf("please enter two numbers: ");
          scanf("%f %f", &n1, &n2);
          answer=n1+n2;
          printf("the answer is: %.2f \n", answer);
       }
       else if (option==2) 
       {
          printf("please enter two numbers: ");
          scanf("%f %f", &n1, &n2);
          answer=n1-n2;
          printf("answer: %.2f \n", answer);
       } 
       else if (option==3) 
       {
          printf("please enter two numbers: ");
          scanf("%f %f", &n1, &n2);
          answer=n1*n2;
          printf("answer: %.2f \n", answer);
       } 
       else if (option==4)
       {
          printf("please enter two numbers: ");
          scanf("%f %f", &n1, &n2);
          answer=n1/n2;
          printf("answer: %.2f \n", answer);
       } 
       else if (option==5) 
       {
          printf("exiting program.\n");
          break;
       }
       else 
       printf("unknown,please try again.\n");
    }

    return 0;
}