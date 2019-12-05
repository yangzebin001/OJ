/*
 * @Date: 2019-11-26 16:28:54
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-26 17:12:39
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 550;

int Map[MAXN][MAXN];
int N,M,S,D;
int saveteam[MAXN];
int vis[MAXN];
int pre[MAXN];
int lowcost[MAXN];
int st[MAXN];
int cnt[MAXN];
void Dijkstra(int N,int S){
    for(int i = 0; i < N; i++){
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
        cnt[i] = 0;
    }

    lowcost[S] = 0;
    st[S] = saveteam[S];
    cnt[S] = 1;
    for(int j = 0; j < N; j++){
        int k = -1;
        int Min = INF;
        for(int i = 0; i < N; i++){
            if(!vis[i] && lowcost[i] < Min){
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                if(lowcost[k] + Map[k][i] < lowcost[i]){
                    lowcost[i] = lowcost[k] + Map[k][i];
                    pre[i] = k;
                    st[i] = st[k]+saveteam[i]; 
                    cnt[i] = cnt[k];
                }else if(lowcost[k] + Map[k][i] == lowcost[i]) {
                    cnt[i] += cnt[k];
                    if(saveteam[i] + st[k] > st[i]){
                        st[i] = saveteam[i] + st[k];
                        pre[i] = k;
                    }
                }
            }
        }
    }
}

void dfs(int D){
    if(pre[D] == -1){
        return;
    }
    dfs(pre[D]);
    printf("%d ",pre[D]);
}

int main(){
    freopen("in.txt","r",stdin);
    memset(Map,INF,sizeof(Map));
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(int i = 0; i < N; i++){
        scanf("%d",&saveteam[i]);
    }
    for(int i = 0; i < M; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        Map[a][b] = c;
        Map[b][a] = c;
    }
    Dijkstra(N,S);
    
    printf("%d %d\n",cnt[D],st[D]);
    dfs(D);
    printf("%d",D);
    return 0;
}