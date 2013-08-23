#include<stdio.h>
void mergesort(long[] , long , long);
int main()
{
    long no_of_test , n , i;
    long * arr;
    scanf("%ld" , &n);
    arr = (long*)malloc(n*sizeof(long));
    for(i=0;i<n;i++)
    {
        scanf("%ld",&arr[i]);
    }
    mergesort(arr , 0 , n-1);
    for(i=0;i<n;i++)
    {
        printf("%ld\n" , arr[i]);
    }
    return 0;
}
void mergesort(long a[], long low, long high) {
 int i = 0;
 int length = high - low + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int working[length];

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
    if(working[merge1] > working[merge2])
     a[i + low] = working[merge2++];
    else
     a[i + low] = working[merge1++];
   else
    a[i + low] = working[merge2++];
  else
   a[i + low] = working[merge1++];
 }
}
