/*
 * @Date: 2019-08-26 20:56:45
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 22:03:51
 */
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;
int N;
int M[MAXN][MAXN];
int lowc[MAXN];
int vis[MAXN];
char s[MAXN][10];
int cal(int a,int b){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(s[a][i] != s[b][i]) cnt++;
    }
    return cnt;
}

int Prim(int N){
    memset(lowc,INF,sizeof(lowc));
    memset(vis,0,sizeof(vis));
    int ans = 0;
    vis[0] = 1;
    for(int i = 1; i < N; i++) lowc[i] = M[0][i];
    for(int i = 1; i < N; i++){
        int minc = INF;
        int p = -1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && lowc[j] < minc){
                minc = lowc[j];
                p = j;
            }
        }
        if(p == -1) return -1;
        ans += minc;
        vis[p] = 1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && M[p][j] < lowc[j]){
                lowc[j] = M[p][j];
            }
        }
    }
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d",&N) && N){
        memset(M,INF,sizeof(M));
        for(int i = 0; i < N; i++){
            scanf("%s",s[i]);
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                M[i][j] = M[j][i] = cal(i,j);
            }
        }
        printf("The highest possible quality is 1/%d.\n",Prim(N));
    }
    return 0;
}
