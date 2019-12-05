/*
 * @Date: 2019-10-21 21:36:32
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-21 22:01:35
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL ans = 0;
const int MAXN = 1e4+10;
int C[MAXN],Y[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    int N,S,ci,yi;
    scanf("%d%d",&N,&S);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&C[i],&Y[i]);
    }
    for(int i = 1; i < N; i++) C[i] = min(C[i-1]+S,C[i]);
    for(int i = 0; i < N; i++) ans += (C[i] * Y[i]);
    printf("%lld",ans);
    return 0;
}