#include<stdio.h>

int main()

{

    int t, tc, k;

    int i, j;

    char ch[1000005];

    scanf("%d", &tc);

    for(t=0;t<tc;t++)

    {

        scanf("%s", ch);

        for(i=0;ch[i]!='\0';i++);

        k=1;

        while(ch[i-k] == '9' && k<=i) ch[i-k++] = '0';

        if(k>i) {i++; for(j=i-1;j>0;j--) ch[j] = ch[j-1];  ch[0] = '1'; }

        else ch[i-k]++;

        for(j=0;j<i/2;j++)

        {

            if(ch[j] > ch[i-j-1])

                 ch[i-j-1] = ch[j];

            else if(ch[j] < ch[i-j-1])

            {

                k=1;

                while(ch[i-j-1-k] == '9') ch[i-j-1-k++] = '0';

                ch[i-j-1-k]++;

                ch[i-j-1] = ch[j];

            }

        }

        printf("\n");

        for(j=0;j<i;j++)

        {

            printf("%c", ch[j]);

        }

        printf("\n");

    }

    return 0;

}
