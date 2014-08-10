#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)
typedef pair<int, int> Point;
typedef set<Point> path;
void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int DFS (int a[][1001], int M, int N, path p1, Point p) {
    Point n, e,w,s;
    n = e = w = s = p;
    n.first -= 1;
    e.second +=1;
    s.first +=1;
    w.second -=1;
    if (p1.find(n) != p1.end() && p1.find(e) != p1.end() && p1.find(w) != p1.end() && p1.find(s) != p1.end())
        return 0;
    if (p.first == m-1 && p.second == n-1)
        return 1;
    int val1 = DFS(a, M, N, p1.add(n), n)
    p1.erase(n);
    int val1 = DFS(a, M, N, p1.add(e), e)
    p1.erase(e);
    int val1 = DFS(a, M, N, p1.add(s), s)
    p1.erase(s);
    int val1 = DFS(a, M, N, p1.add(w), w)
    p1.erase(w);
}

int numberOfPaths(int a[][1001],int M, int N) {
    Point p;
    p.first = 0;
    p.second = 0;
    int answer;
    path p1;
    p1.add(p);
    answer = DFS(a, M, N,p1)
}

int main()
{
    INPUT_FROM_FILE();

    return 0;
}
