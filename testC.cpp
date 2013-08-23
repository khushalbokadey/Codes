#include<stdio.h>

 int main()

 {

 int a[3];

 int *I;

 a[0]=100;a[1]=200;a[2]=300;

 I=a;

 printf("%d\n", ++*I);

 printf("%d\n", *++I);



 printf("%d\n", (*I)--);

 printf("%d\n", *I);
    return 0;
 }
