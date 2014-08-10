#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

string multiply(string a, string b) {
    size_t total_len= a.length() + b.length();
    string result(total_len, '0');

    int num;
    int i, j, index;
    int last_pos_i, last_pos_j, last_pos_k;
    last_pos_i= total_len - 1;

    for (i= b.length() - 1; i >= 0; i --) {
        last_pos_j= last_pos_i;
        for (j= a.length() - 1; j >=0; j --) {
            last_pos_k= last_pos_j;
            num= INT(a.at(j)) * INT(b.at(i));
            while (num) {
                num += INT(result.at(last_pos_k));
                result.at(last_pos_k)= CHAR(num % 10);
                num= num / 10;
                last_pos_k --;
            }
            last_pos_j --;
        }
        last_pos_i --;
    }
    index = 0;
    for (i=0; i<result.length(); i++) {
        if (result.at(i) == '0')
            index++;
        else
            break;
    }
    return result.substr(index, result.length() - index);
}


int main()
{
    INPUT_FROM_FILE();
    int n;
    string num1, num2;
    cin >> n;
    while (n--) {
        cin >> num1 >> num2;
        cout << multiply(num1, num2) << "\n";
    }
    return 0;
}
