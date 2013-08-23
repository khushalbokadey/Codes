#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc , char*argv[])
{
    if(argc==3)
    {
        ifstream myfile (argv[1]);
        ofstream outputfile;
        outputfile.open (argv[2]);
        char ch;
        if(myfile)
        {
            do
            {
                myfile.get(ch);
                cout<<"\n"<<(int)ch;
                outputfile<<ch;
            }while(myfile);
        }

        outputfile.close();
    }
    return 0;
}
