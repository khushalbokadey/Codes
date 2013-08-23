#include<iostream>
#include<math.h>
#include<cstdio>
#include<stdlib.h>

using namespace std;

#define ABS(a) (a > 0 ? a : -(a))
#define MAX(a, b) (a > b ? a : b)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}


int main()
{
    //INPUT_FROM_FILE();

    int no_of_points, i, j, k,  min_index;
    long long int pointx[100003], pointy[100003], sum=0;
    double difference, midx=0, midy=0;
    long double minimumdistance;

    cin>>no_of_points;

    for(i=0;i<no_of_points;i++)
    {
        cin>>pointx[i]>>pointy[i];
        midx+= (long double)pointx[i]/no_of_points;
        midy+= (long double)pointy[i]/no_of_points;
    }

    minimumdistance = sqrt((midx-pointx[0])*(midx-pointx[0]) + (midy-pointy[0])*(midy-pointy[0]));
    min_index=0;
    for(i=1;i<no_of_points;i++)
    {
        difference = sqrt((midx-pointx[i])*(midx-pointx[i]) + (midy-pointy[i])*(midy-pointy[i]));
        if(difference < minimumdistance)
        {
            minimumdistance = difference;
            min_index = i;
        }
    }

    for (i=0; i<no_of_points; i++)
    {
        sum += MAX((ABS(pointx[min_index]-pointx[i])), (ABS(pointy[min_index]-pointy[i])));
	}

	cout<<sum<<"\n";

    return 0;
}
