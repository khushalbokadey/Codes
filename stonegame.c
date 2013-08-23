#include<stdio.h>
int main()
{
	int no_of_test , S[100] , piles;
	int i , j , chance;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
		chance=0;
		scanf("%d" , &piles);
		for(i=0;i<piles;i++)
		{
			scanf("%d" , &S[i]);
		}
		for(i=0;i<piles;i++)
		{
			chance = chance + S[i]/(i+1);
		}
		if(chance%2==0)
			printf("BOB\n");
		else
			printf("ALICE\n");
		no_of_test--;
	}
	return 0;
}
