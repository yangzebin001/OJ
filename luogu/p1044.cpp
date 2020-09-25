#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL C[40][40];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    printf("%lld",C[2*n][n]-C[2*n][n-1]);
    return 0;
}
