/*
 * @Date: 2019-08-29 19:39:53
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-29 20:16:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int M[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];

int toNum(char *s){
    int len = strlen(s);
    int flag = 1;
    int ans = 0;
    for(int i = 0; i < len; i++){
        if(i == 0 && s[i] == '-') flag = -1;
        else if(s[i] == 'x') return INF;
        else ans = ans * 10 + (s[i]-'0');
    }
    return ans*flag;
}

int Dijkstra(int S, int N){
    for(int i = 0; i < N; i++){
        dis[i] = i == S ? 0 : INF;
        vis[i] = 0;
    }
    for(int i = 0; i < N; i++){
        int Min = INF;
        int k = -1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dis[j] < Min){
                Min = dis[j];
                k = j;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dis[j] > dis[k] + M[k][j]){
                dis[j] = dis[k] + M[k][j];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans,dis[i]);
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++){
        char s[100];
        for(int j = 0; j < i; j++){
            scanf("%s",s);
            M[i][j] = M[j][i] = toNum(s);
        }
    }
    printf("%d",Dijkstra(0,n));
    return 0;
}