#include<stdio.h>

#include<string.h>



void convert(char[], int);

short unsigned int priority(char temp);

int main()

{

    int tc = 1, i;

    scanf("%d", &tc);

    char str[400];

    for(i=0;i<tc;i++)

    {

        scanf("%s", str);

        convert(str, 1);

        printf("\n");

    }

    return 0;

}

void convert(char str[], int start)

{

    char stack[280], top = 0;

    int i;

    for(i=start;i<strlen(str);i++)

    {

        switch(str[i])

        {

            case '(':

                   stack[top++] = str[i];

                   break;

            case ')':

                        //printf("%d ", top);

                    while(top>0 && stack[--top] != '(')

                    {

                        printf("%c", stack[top]);

                    }

                    break;

            case '+':

            case '-':

            case '*':

            case '/':

            case '^':

            case '%':

                    while(top>1 && stack[top-1] != '(' && priority(str[i]) <= priority(stack[top-1]))

                    {

                        printf("%c", stack[--top]);

                    }

                    stack[top++] = str[i];

                    break;

            default:

                    printf("%c", str[i]);

                    break;

        }

        /*for(int j=0;j<top;j++)

        {

            printf("%c ", stack[j]);

        }

        printf("\n");*/

    }

}

short unsigned int priority(char temp)

{

    if(temp=='^')

        return 3;

    else if((temp=='*') || (temp=='/') || (temp=='%'))

        return 2;

    else

        return 1;

}
