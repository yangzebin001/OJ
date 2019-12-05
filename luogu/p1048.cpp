/*
 * @Date: 2019-11-15 14:42:55
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-15 15:10:27
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
const int MAXN = 1e3+10;
int T[MAXN],S[MAXN];
int f[MAXN];//表示选择第i件草药后，时间j内获得的最大价值
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= M; i++){
        scanf("%d%d",&T[i],&S[i]);
    }
    for(int i = 1; i <= M; i++){
        for(int j = N; j >= T[i]; j--){
            if(j >= T[i]){
                f[j] = max(f[j],f[j-T[i]]+S[i]);
            }
        }
    }
    
    printf("%d",f[N]);
    return 0;
}