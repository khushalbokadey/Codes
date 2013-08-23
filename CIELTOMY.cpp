#include<iostream>

using namespace std;

int minpathcost , no_of_path;

int matrix[50][50] = {0};
int no_of_test , N , M , A , B , C;
int i , j;

void findnoofpath();
int getminnoofpath(int , int);

int main()
{
    cin >> no_of_test;

    while(no_of_test)
    {
        for(i=0;i<50;i++)
        {
            for(j=0;j<50;j++)
            {
                matrix[i][j] = 0;
            }
        }
        cin>>N>>M;
        no_of_path = 0;
        for(i=0;i<M;i++)
        {
            cin>> A >> B >> C;
            matrix[A-1][B-1] = C;
            matrix[B-1][A-1] = C;
        }
        minpathcost = C;
        findnoofpath();
        cout<<no_of_path<<"\n";
        no_of_test--;
    }

    return 0;
}

void findnoofpath()
{
    int pathcost;
    minpathcost = matrix[0][N-1];
    for(j=1;j<N;j++)
    {
        pathcost = getminnoofpath(0 , j);
        if((pathcost<minpathcost && pathcost!=0) || minpathcost==0)
        {
            minpathcost = pathcost;
            no_of_path = 1;
        }
        else if(pathcost == minpathcost)
        {
            no_of_path++;
        }
    }
}

int getminnoofpath(int a , int b)
{
    int pathcost = 0 , temppathcost;
    if(matrix[a][b]!=0)
    {
        pathcost = matrix[a][b];
        if(b == N-1)
        {
            return pathcost;
        }
        else
        {
            temppathcost = getminnoofpath(b,b+1);
            if(temppathcost!=0)
            {
                pathcost += temppathcost;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        pathcost = 0;
    }
    return pathcost;
}
