  #include <iostream>

    using namespace std;

    int main(void)

    {

        int a,n;

        cin>>n;

        for(int t=0;t<n;t++)

        {

            cin>>a;

            int i=0,c=5;

            while((a/c)>0)

            {
                i=i+(a/c);

                c=c*5;

            }

            cout<<i<<"\n";

        }



        return 0;

    }
