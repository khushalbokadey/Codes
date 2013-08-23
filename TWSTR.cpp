#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct reciepe
{
    char S[1003];
    long V;
};
void mergesort(struct reciepe[] , int , int);

int main()
{
    int N , Q , i , flag , j , k ,found ;
    string query;
    struct reciepe obj[1000];
    scanf("%d" , &N);
    for(i=0;i<N;i++)
    {
        scanf("%s",obj[i].S);
        scanf("%ld",&obj[i].V);
    }
    mergesort(obj,0,N-1);
    scanf("%d",&Q);
    getline(cin,query);
    for(i=0;i<Q;i++)
    {
        getline(cin,query);
        found=0;
        for(j=0;j<N;j++)
        {
            flag=1;
            for(k=0;k<query.length();k++)
            {
                if(query.at(k)!= obj[j].S[k])
                {
                    flag=0;
                    break;
                }
            }
            //cout<<" "<<k<<" "<<obj[j].S;
            if(flag==1)
            {
                cout<<"\n"<<obj[j].S;
                found=1;
                break;
            }
        }
        if(found==0)
        {
            cout<<"\nNO";
        }
    }
    return 0;
}
void mergesort(struct reciepe a[], int low, int high)
{
 int i = 0;
 int length = high - low + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 struct reciepe working[length];

 if(low == high)
  return;

 pivot  = (low + high) / 2;

 mergesort(a, low, pivot);
 mergesort(a, pivot + 1, high);

 for(i = 0; i < length; i++)
  working[i] = a[low + i];

 merge1 = 0;
 merge2 = pivot - low + 1;

 for(i = 0; i < length; i++) {
  if(merge2 <= high - low)
   if(merge1 <= pivot - low)
    if(working[merge1].V < working[merge2].V)
    {
       a[i + low] = working[merge2++];
    }

    else
    {
       a[i + low] = working[merge1++];
    }

   else
   {
       a[i + low] = working[merge2++];
   }

  else
  {
      a[i + low]= working[merge1++];
  }

 }
}
