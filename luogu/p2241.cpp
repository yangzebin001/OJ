#include<iostream>
#include<cstdio>
using namespace std;

long long tot, square;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            square += min(i,j);
            tot += i*j;
        }
    }
    printf("%lld %lld", square, tot-square);
    return 0;
}