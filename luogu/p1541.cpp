/*
 * @Date: 2019-11-13 21:53:14
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-14 19:50:58
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN =41;
int f[MAXN][MAXN][MAXN][MAXN];//分别代表四种卡片
int g[5],num[351],N,M;

int main(){
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; i++){
        scanf("%d",&num[i]);
    }
    for(int i = 0; i < M; i++){
        int a;
        scanf("%d",&a);
        g[a]++;
    }
    f[0][0][0][0] = num[1];
    for(int i = 0; i <= g[1]; i++){
        for(int j = 0; j <= g[2]; j++){
            for(int k = 0; k <= g[3]; k++){
                for(int p = 0; p <= g[4]; p++){
                    int dd = i + j*2 + k*3+p*4+1;
                    if(i != 0) f[i][j][k][p] = max(f[i][j][k][p],f[i-1][j][k][p]+num[dd]);
                    if(j != 0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j-1][k][p]+num[dd]);
                    if(k != 0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j][k-1][p]+num[dd]);
                    if(p != 0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j][k][p-1]+num[dd]);
                }
            }
        }
    }
    printf("%d",f[g[1]][g[2]][g[3]][g[4]]);
    return 0;
}