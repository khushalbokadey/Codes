#include<stdio.h>
#include<iostream>
using namespace std;
int getEqualSumSubstring(string);
int main()
{
    int a;
    a = getEqualSumSubstring("986561517416921217551395112859219257312");
    printf("%d" , a);
    return 0;
}
int getEqualSumSubstring(string s)
{
    int i=0,j=i,foundLength=0;
    for(i=0;i<s.length();i++)
    {
        for(j=i;j<s.length();j++)
        {
            int temp = j-i+1;

            if(temp%2==0)
            {
                int leftSum=0,rightSum=0;
                string tempString=s.substr(i,temp);
                // printf("%d ",tempString.length());
                for(int k=0;k<temp/2;k++)
                {
                    leftSum=leftSum+tempString[k]-48;
                    rightSum=rightSum+tempString[k+(temp/2)]-48;
                }
                if((leftSum==rightSum)&&(leftSum!=0))
                    if(tempString.length()>foundLength)
                    foundLength=tempString.length();
            }
        }
    }
    return(foundLength);
}
