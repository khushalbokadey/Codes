#include<stdio.h>
#include<stdlib.h>
 int main()
 {
 char *st1[3]= {"Hello","World","Oracle"};
 *st1=st1[2];
 st1[1]=*st1;
 free(st1[0]);
 free(st1[1]);
 printf("%s %s ",st1[1],st1[2]);
 return 0;
 }
