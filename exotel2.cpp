#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}


char op_start_date[10] = {0};
struct date {
    int year, date, month;
};

struct date strToDate (string str) {
    struct date date;
    date.year = date.date = date.month = 0;
    date.year = (str.at(0)-48) * 1000 + (str.at(1)-48) * 100 + (str.at(2)-48) * 10 + (str.at(3)-48) * 1;
    date.date = (str.at(8)-48) * 10 + (str.at(9)-48) * 1;
    date.month = (str.at(5)-48) * 10 + (str.at(6)-48) * 1;
    return date;
};

int getLastDay (int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;

        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
    }
    return 0;
}

void dateToChar(struct date date) {
    char op_end_date[11] = {0};
    op_end_date[10] = '\0';
    op_end_date[0] = date.year/1000 + 48;
    date.year = date.year%1000;
    op_end_date[1] = date.year/100 + 48;
    date.year = date.year%100;
    op_end_date[2] = date.year/10 + 48;
    date.year = date.year%10;
    op_end_date[3] = date.year%10 + 48;
    op_end_date[4] = '-';
    op_end_date[5] = date.month/10 + 48;
    op_end_date[6] = date.month%10 + 48;
    op_end_date[7] = '-';
    op_end_date[8] = date.date/10 + 48;
    op_end_date[9] = date.date%10 + 48;
    cout << op_end_date << "\n";
}

int main()
{
    INPUT_FROM_FILE();
    string reg_inp, test_inp;
    int i, start_date, end_date;
    struct date reg_date, test_date, op_start, op_end;
    cin >> reg_inp >> test_inp;
    reg_date = strToDate(reg_inp);
    test_date = strToDate(test_inp);
    start_date = reg_date.date;
    if (start_date == 1)
        end_date = 31;
    else
        end_date = start_date - 1;
    if (test_date.date == start_date) {
        op_start.date = start_date;
        op_start.month = test_date.month;
        op_start.year = test_date.year;
        if (test_date.date == 1) {
            op_end.date = getLastDay(test_date.month);
            if (test_date.month == 2 && test_date.year%4 == 0)
                op_end.date = 29;
            op_end.month = test_date.month;
            op_end.year = test_date.year;
        } else {
            op_end.date = end_date;
            op_end.month = (test_date.month+1) % 12;
            if (op_end.month == 0) {
                op_end.month = 12;
            }
            if (op_end.month == 1) {
                op_end.year = test_date.year+1;
            } else {
                op_end.year = test_date.year;
            }
            if (op_end.month == 2) {
                int lastdate = getLastDay(2);
                if (op_end.date > lastdate) {
                    if (op_end.year%4 == 0) {
                        op_end.date = 29;
                    }
                    else {
                        op_end.date = 28;
                    }
                }
            }
        }
    } else {
        op_start.date = start_date;
        op_start.year = test_date.year;
        if (start_date > test_date.date) {
            op_start.month = test_date.month-1;
            if (op_start.month == 0) {
                op_start.month = 12;
                op_start.year = test_date.year -1;
            }
        }
        else
            op_start.month = test_date.month;
        if (op_start.month == 2) {
                int lastdate = getLastDay(2);
                if (op_start.date > lastdate) {
                    if (op_start.year%4 == 0) {
                        op_start.date = 29;
                    }
                    else {
                        op_start.date = 28;
                    }
                }
        }

        op_end.date = end_date;
         if (start_date < test_date.date) {
            op_end.month = (test_date.month+1)%12;
            if (op_end.month == 0) {
                op_end.month = 12;
                op_end.year = test_date.year + 1;
            }
        }
        else
            op_end.month = test_date.month;
        if (op_end.month == 1) {
            op_end.year = test_date.year+1;
        } else {
            op_end.year = test_date.year;
        }
        if (op_end.month == 2) {
            int lastdate = getLastDay(2);
            if (op_end.date > lastdate) {
                if (op_end.year%4 == 0) {
                    op_end.date = 29;
                }
                else {
                    op_end.date = 28;
                }
            }
        }

    }
    dateToChar(op_start);
    dateToChar(op_end);
    //cout << op_end_date << "\n";
    //cout << op_start_date << "\n";
    //cout << op_start.year << "-" << op_start.month << "-" << op_start.date << "\n";
    //cout << op_end.year << "-" << op_end.month << "-" << op_end.date << "\n";
    return 0;
}
