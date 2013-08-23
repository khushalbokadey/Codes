#include<stdio.h>
int main(){int i=10,j,count;char word[21];while(i){count=1;scanf("%s",word);for(j=0;word[j]!='\0';j++){if(word[j]=='T'||word[j]=='D'||word[j]=='L'||word[j]=='F')count*=2;}printf("%d\n",count);i--;}return 0;}
