#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc , char*argv[])
{
    if(argc==3)
    {
        ifstream inputfile (argv[1]);
        ofstream outputfile (argv[2]);

        int no_of_attacks , i;
        char ch;
        while(inputfile)
        {
            no_of_attacks = 0;
            i=1;
            inputfile.get(ch);
            while(ch!=' ')
            {
                no_of_attacks = (no_of_attacks*i)+((int)ch-48);
                i*=10;
                inputfile.get(ch);
            }
        }

        outputfile.close();
    }
    return 0;
}
