/*
 * @Date: 2019-08-29 09:27:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-29 11:08:09
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];

int dis[MAXN];
int vis[MAXN];
int inq[MAXN];

int E,N;
void init(){
    for(int i = 0; i <= E; i++){
        for(int j = 0; j <= E; j++){
            G[i][j] = 0;
        }
    }
}

int SPFA(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= N; i++) dis[i] = G[1][i];
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(q.size()){
        int v = q.front(); q.pop();
        vis[v] = 0;
        for(int i = 1; i <= E; i++){
            if(v == 1 && G[v][i] && !vis[i]){
                q.push(i);
                vis[i] = 1;
                continue;
            }
            if(dis[i] < min(dis[v],G[v][i])){
                dis[i] = min(dis[v],G[v][i]);
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                    
                }
            }
        }
    }
    return dis[E];
    
}

int main(){
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d",&E,&N);
        init();
        for(int j = 0; j < N; j++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            G[a][b] = G[b][a] = w;
        }

        printf("Scenario #%d:\n%d\n\n",i,SPFA());
        
    }
}
