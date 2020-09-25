#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

char getch(int a){
    if(a < 10) return '0'+a;
    return 'A' + (a-10);
}

void dfs(int n, int r){
    if(n == 0) return;
    int m = n%r;
    if(m < 0) m -= r, n += r; //转换余数为正数

    dfs(n/r, r);
    printf("%c", getch(m));
    return;
}

int main(){
    int n,r;
    cin >> n >>r;
    cout << n << "=";
    dfs(n,r);
    printf("(base%d)",r);
    return 0;
}