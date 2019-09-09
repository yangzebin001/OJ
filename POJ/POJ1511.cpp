/*
 * @Date: 2019-08-30 10:53:15
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-30 12:04:35
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1000100;
const long long INF = 1<<30;
struct Edge{
    int to,w;
    Edge(){}
    Edge(int _to, int _w){
        to = _to;
        w = _w;
    }
};
struct qnode{
    int v,d;
    qnode(){}
    qnode(int _v,int _d){
        v = _v;
        d = _d;
    }
    bool operator <(const qnode &c)const{
        return d > c.d;
    }
};
vector<Edge> G1[MAXN];

long long dis[MAXN];
int vis[MAXN];
int aa[MAXN];
int bb[MAXN];
int cc[MAXN];
int tol = 0;

int N,M;
long long ans = 0;

void Dijkstra(int S, int N){
    fill(dis+1,dis+1+N,INF);
    fill(vis+1,vis+1+N,0);
    dis[S] = 0;
    priority_queue<qnode> pq;
    pq.push(qnode(S,dis[S]));
    while(pq.size()){
        int u = pq.top().v; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < G1[u].size(); i++){
            int v = G1[u][i].to;
            int c =  G1[u][i].w;
            if(!vis[v] && dis[v] > dis[u] + c){
                dis[v] = dis[u] + c;
                pq.push(qnode(v,dis[v]));
            }
        }
    }
    for(int j = 1; j <= N; j++){
        ans += dis[j];
    }
}

void init(){
    for(int i = 0; i <= N; i++){
        G1[i].clear();
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        init();
        ans = 0;
        tol = 0;
        for(int i = 0; i < M; i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            G1[a].push_back(Edge(b,w));
            aa[tol] = a;
            bb[tol] = b;
            cc[tol++] = w;
        }

        Dijkstra(1,N);
        init();
        for(int i = 0; i < tol; i++){
            G1[bb[i]].push_back(Edge(aa[i],cc[i]));
        }
        
        Dijkstra(1,N);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}