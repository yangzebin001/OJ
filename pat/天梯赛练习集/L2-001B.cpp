/*
 * @Date: 2019-11-26 17:14:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-26 18:05:04
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 600;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,dis;
    Edge(int to,int dis):to(to),dis(dis){}
};
vector<Edge> G[MAXN];

int N,M,S,D;

int saveteam[MAXN];

bool inq[MAXN];
int dis[MAXN];
int pre[MAXN];
int cnt[MAXN];
int st[MAXN];
int vis[MAXN];
bool SPFA(int S,int N){
    for(int i = 0; i < N; i++){
        dis[i] = i == S ? 0 : INF;
        pre[i] = -1;
        inq[i] = false;
        cnt[i] = 0;
    }
    cnt[S] = 1;
    st[S] = saveteam[S];
    queue<int> q;
    q.push(S);
    inq[S] = true;
    while(q.size()){
        int u = q.front();q.pop();
        inq[u] = false;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].to;
            int d = G[u][i].dis;
            if(dis[v] > dis[u] + d){
                dis[v] = dis[u] + d;
                pre[v] = u;
                cnt[v] = cnt[u];
                st[v] = st[u] + saveteam[v];

                if(!inq[v]){
                    q.push(v);
                    inq[v] =true;
                }
            }else if(dis[v] == dis[u] + d){
                if(st[v] < st[u] + saveteam[v]){
                    cnt[v] += cnt[u];
                    st[v] = st[u] + saveteam[v];
                    pre[v] = u;
                }

                if(!inq[v]){
                    q.push(v);
                    inq[v] =true;
                }
            }
        }
    } 
    return true;
}

void dfs(int D){
    if(pre[D] == -1) return;
    dfs(pre[D]);
    printf("%d ",pre[D]);
}

int ans = 0;
//计算最短路径个数。
void paths(int s){
    if(s == D){
        ans++;
        return;
    }
    for(int i = 0; i < G[s].size(); i++){
        if(dis[G[s][i].to] == dis[s] + G[s][i].dis){
            vis[G[s][i].to] = 1;
            paths(G[s][i].to);
            vis[G[s][i].to] = 0;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(int i = 0; i < N; i++){
        scanf("%d",&saveteam[i]);
    }
    for(int i = 0; i < M; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    SPFA(S,N);
    paths(S);
    printf("%d %d\n",ans,st[D]);
    dfs(D);
    printf("%d",D);
    return 0;
}