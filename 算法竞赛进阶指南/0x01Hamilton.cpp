#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20;
int f[1<<MAXN][MAXN];
int weight[MAXN][MAXN];

int hamilton(int n){
    memset(f,0x3f,sizeof f);
    f[1][0] = 0;
    for(int i = 0; i < 1 << n; i++){
        for(int j = 0; j < n; j++){
            if(i >> j & 1){
                for(int k = 0; k < n; k++){
                    if(i >> k & 1){
                        f[i][j] = min(f[i][j], f[i^(1 << j)][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    return f[(1<<n)-1][n-1];
}

int main(){
    // freopen("in.txt","r",stdin);
    int n;

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&weight[i][j]);
        }
    }
    printf("%d",hamilton(n));
    return 0;
}