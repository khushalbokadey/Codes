#include <iostream>
using namespace std;
int prime(int i)
{
    int j=2;
    while(j<=i/2)
     {
        if(i%j==0)
        {
        return 0;
        }
        else
        j++;
      }
      if(i==j/2)
      return 1;
}
int palindrome(int i)
{
    int num=i, rev=0,rem;
    while(num)
      {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
      }

    if(rev==i)
        return 1;
        else
        return 0;
}

int main()
{
 int i;
 cin>>i;
 up:
 if(prime(i)&& palindrome(i))
 cout<<i;
 else
 {
    i++;
    goto up;
 }

return 0;
}
