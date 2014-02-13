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

    set<char> cust_set;
    set<char>::iterator it;
    int i, len, curr_count, answer;
    bool arr[27] = {0};
    len = customers.length();
    answer = 0;
    curr_count = numComputers;
    for (i=0; i<len; i++) {
        it = cust_set.find(customers.at(i));
        if (it == cust_set.end() && curr_count > 0) {
            cust_set.insert(customers.at(i));
            arr[customers.at(i) - 65] = 1;
            curr_count--;
        } else if (it == cust_set.end() && curr_count <= 0) {
            cust_set.insert(customers.at(i));
            answer++;
        } else if (it != cust_set.end() && arr[customers.at(i) - 65] == 1) {
            cust_set.erase(customers.at(i));
            arr[customers.at(i) - 65] = 0;
            curr_count++;
        } else if (it != cust_set.end() && arr[customers.at(i) - 65] == 0) {
            cust_set.erase(it);
        }
        cout << customers.at(i) << " " << curr_count << "\n";
        if (curr_count > 0) {
            for (it=cust_set.begin(); it!=cust_set.end(); ++it) {
                cout << *it << " ";
                if (arr[customers.at(i) - 65] == 0) {
                    arr[customers.at(i) - 65] = 1;
                    curr_count--;
                    answer--;
                }
            }
        }
        cout << endl;
        cout << customers.at(i) << " " << curr_count << "\n";
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

