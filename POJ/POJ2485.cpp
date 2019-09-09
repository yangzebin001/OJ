/*
 * @Date: 2019-08-27 08:36:51
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-27 09:32:14
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 600;
const int INF = 0x3f3f3f3f;

int M[MAXN][MAXN];
int N;

int lowc[MAXN];
int vis[MAXN];

int Prim(int N){
    memset(lowc,INF,sizeof(lowc));
    memset(vis,0,sizeof(vis));
    vis[0] = 1; 
    int ans = 0;
    int tans = 0;
    for(int i = 1; i < N; i++) lowc[i] = M[0][i];
    for(int i = 1; i < N; i++){
        int minc = INF;
        int k = -1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && minc > lowc[j]){
                minc = lowc[j]; k = j;
            }
        }
        if(k == -1) return -1;
        ans += minc;
        tans = max(tans,minc);
        vis[k] = 1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && M[k][j] < lowc[j]){
                lowc[j] = M[k][j];
            }
        }
    }
    return tans;
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d",&M[i][j]);
            }
        }
        printf("%d\n",Prim(N));
    }
    return 0;
}