#include<stdio.h>
int main()
{
	long score1 , s1 , score2 , s2 , games , max;
	int i , winner;
	scanf("%d" , &games);
	score1 = 0 ;
	score2 = 0;
	max=0;
	for(i=0;i<games;i++)
	{
		scanf("%ld" , &s1);
		scanf("%ld" , &s2);
		score1 = score1 + s1;
		score2 = score2 + s2;
		if(score1-score2> max)
		{
			max = score1-score2;
			winner = 1;
		}
		else if (score2- score1 > max)
		{
			max = score2-score1;
			winner = 2;
		}
	}
	printf("%d %ld" , winner , max);
	return 0;
}
