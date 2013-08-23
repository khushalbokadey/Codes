#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    float y;
    scanf("%d %f",&x , &y);
    if(x%5!=0)
    {
        printf("%.2f", y);
    }
    else if((y-0.50)<x)
    {
        printf("%.2f", y);
    }
    else
    {
        printf("%.2f" , (y-x-.50));
    }
    return 0;
}
