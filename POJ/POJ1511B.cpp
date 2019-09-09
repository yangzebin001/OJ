/*
 * @Date: 2019-08-30 14:43:01
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-30 15:03:30
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1000010;
const int INF = 0x3f3f3f3f;
struct node{
    int to,w;
    node(){}
    node(int _to, int _w){
        to = _to;
        w = _w;
    }
};

vector<node> G[MAXN];
int dis[MAXN];
int aa[MAXN],bb[MAXN],cc[MAXN];

int N,M;

long long ans;

void SPFA(int S,int N){
    for(int i = 1; i <= N; i++){
        dis[i] = S == i ? 0 : INF;
    }
    queue<int> q;
    q.push(S);
    while(q.size()){
        int v = q.front();q.pop();
        for(int i = 0; i < G[v].size(); i++){
            int u = G[v][i].to;
            int w = G[v][i].w;
            if(dis[u] > dis[v] + w){
                dis[u] = dis[v] + w;
                q.push(u);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        ans += dis[i];
    }
}
void init(){
    for(int i = 0; i <= N; i++){
        G[i].clear();
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        ans = 0;
        scanf("%d%d",&N,&M);
        init();
        for(int i = 0; i < M; i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            G[a].push_back(node(b,w));
            aa[i] = a;
            bb[i] = b;
            cc[i] = w;
        }
        SPFA(1,N);
        init();
        for(int i = 0; i < M; i++){
            G[bb[i]].push_back(node(aa[i],cc[i]));
        }
        SPFA(1,N);
        printf("%lld\n",ans);
    }
    return 0;
}