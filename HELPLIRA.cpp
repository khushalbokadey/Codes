#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define floatIn() ({ float x; scanf("%f", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

struct Coordinates {
    float x, y;
};

int main()
{
    INPUT_FROM_FILE();
    int no_of_triangles, max_index=0, min_index=0, i;
    float max_area=0, min_area = 0, area;
    struct Coordinates A, B, C;
    no_of_triangles = in();
    i = 1 ;
    while (no_of_triangles--) {
        A.x = floatIn();
        A.y = floatIn();
        B.x = floatIn();
        B.y = floatIn();
        C.x = floatIn();
        C.y = floatIn();
        area = ((A.x * (B.y - C.y)) + (B.x * (C.y - A.y)) + (C.x * (A.y - B.y))) / 2;
        area = abs(area);
        if (area >= max_area) {
            max_area = area;
            max_index = i;
        }
        if (area <= min_area || i == 1) {
            min_area = area;
            min_index = i;
        }
        i++;
    }

    cout<< min_index << " " << max_index << "\n";
    return 0;
}
