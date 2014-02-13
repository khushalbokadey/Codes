#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}
int runCustomerSimulation(int numComputers, string customers) {

    int i, len, curr_count, answer;
    int arr[27] = {0};
    len = customers.length();
    answer = 0;
    curr_count = numComputers;
    for (i=0; i<len; i++) {

        if (arr[customers.at(i) - 65] == 1) {
            arr[customers.at(i) - 65] = 0;
            curr_count++;
        }
         else if (arr[customers.at(i) - 65] == 0 && curr_count > 0) {
            arr[customers.at(i) - 65] = 1;
            curr_count--;
        } else if (curr_count <= 0 && arr[customers.at(i) - 65] == 0) {
            arr[customers.at(i) - 65] = -1;
            answer++;
        } else if (arr[customers.at(i) - 65] == -1) {
            arr[customers.at(i) - 65] = 0;
        }
    }
    return answer;
}

int main()
{
    //INPUT_FROM_FILE();
    cout << runCustomerSimulation (2, "ABBAJJKZKZ") << "\n";
    cout << runCustomerSimulation (3, "GACCBDDBAGEE") << "\n";
    cout << runCustomerSimulation (3, "GACCBGDDBAEE") << "\n";
    cout << runCustomerSimulation (1, "ABCBCA") << "\n";
    return 0;
}

