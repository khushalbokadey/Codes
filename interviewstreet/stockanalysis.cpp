#include<iostream>
#include<stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int N, D, *pointx, *pointy;
    int i, j, currentindex;

    cin>>N>>D;
    pointx = (int*)malloc(sizeof(int) * N);
	pointy = (int*)malloc(sizeof(int) * N);

    for(i=0;i<N;i++)
    {
        cin>>pointx[i]>>pointy[i];
    }

    vector<int> outputpointx;
    vector<int> outputpointy;
    vector<int>::iterator iter;
    vector<int>::iterator iter1;

    iter = outputpointx.begin();
    iter1 = outputpointy.begin();

    outputpointx.push_back (pointx[0]);
    outputpointy.push_back (pointy[0]);

    currentindex = 0;
    do
    {
        for(j=N-1; j>currentindex;j--)
        {
            float dist, slope;
            slope = ((float)(pointy[j]-pointy[currentindex])/(pointx[j]-pointx[currentindex]));
            bool flag = true;

            for(i=currentindex+1 ; i<j; i++)
            {
                dist = (slope*pointx[i]) - (slope*pointx[currentindex]) + pointy[currentindex];
                float diff;
                if(dist<pointy[i])
                {
                    diff = pointy[i]-dist;
                }
                else
                {
                    diff = dist - pointy[i];
                }
                if(diff>=D)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                outputpointx.push_back (pointx[j]);
                outputpointy.push_back (pointy[j]);
                currentindex = j;
                break;
            }
        }
    }while(currentindex!=N-1);

    cout<<outputpointx.size()<<"\n";
    for(iter = outputpointx.begin() , iter1=outputpointy.begin() ; iter< outputpointx.end() ; iter++, iter1++)
    {
        cout<<*iter<<" "<<*iter1<<"\n";
    }

    return 0;
}
