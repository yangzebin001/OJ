#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 20000100;

int d[MAXN][2];

int main(){
    d[1][0] = 1;
    d[1][1] = 1;
    int n;
    scanf("%d",&n);
    int x,y;
    x = 1,y = 2;
    int i = 2;
    int flag = -1;
    while(i <= 10000100){
        if(x == 0){
            x = 1;
            flag = -flag;
        }
        if(y == 0){
            y = 1;
            flag = -flag;
        }
        d[i][0] = x;
        d[i][1] = y;
        i++;
        x-=flag;y+=flag;
    }
    printf("%d/%d",d[n][0],d[n][1]);

    return 0;
}