/*
 * @Date: 2019-09-03 10:12:34
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-03 11:27:48
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 30;
const int INF = 0x3f;

int M[MAXN][MAXN];

int dis[MAXN];
int vis[MAXN];
int Prim(int N){
    for(int i = 0; i < N; i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    vis[0] = 1;
    int ans = 0;
    for(int i = 1; i < N; i++) dis[i] = M[0][i];
    for(int i = 1; i < N; i++){
        int k = -1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && (k == -1 || dis[k] > dis[j])){
                k = j;
            }
        }
        ans += dis[k];
        vis[k] = 1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dis[j] > M[k][j]){
                dis[j] = M[k][j];
            }
        }
    }
    return ans;
}




int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n){
        memset(M,INF,sizeof(M));
        for(int i = 0; i < n-1; i++){
            char c[2];int a;
            scanf("%s%d",c,&a);
            for(int j = 0; j < a; j++){
                char b[2]; int d;
                scanf("%s%d",b,&d);
                if(d < M[c[0]-'A'][b[0]-'A'] ){
                    M[b[0]-'A'][c[0]-'A'] = M[c[0]-'A'][b[0]-'A'] = d;
                }
            }
        }
        printf("%d\n",Prim(n));
    }
    return 0;
}