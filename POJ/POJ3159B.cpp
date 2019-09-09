/*
 * @Date: 2019-08-31 10:39:20
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-31 11:00:30
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 30010;
const int MAXE = 150010;
const int INF = 0x3f3f3f3f;
int head[MAXN];
int vis[MAXN];

int Q[MAXN];
int dis[MAXN];

struct Edge{
    int to,w,next;
}edge[MAXE];
int tol;

void add(int a,int b,int w){
    edge[tol].to = b;
    edge[tol].w = w;
    edge[tol].next = head[a];
    head[a] = tol++;
}

void SPFA(int start, int n){
    int top = 0;
    for(int v = 1; v <= n; v++){
        if(v == start){
            Q[top++] = v;
            vis[v] = 1;
            dis[v] = 0;
        }else{
            vis[v] = 0;
            dis[v] = INF;
        }
    }

    while(top != 0){
        int u = Q[--top];
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    vis[v] = 1;
                    Q[top++] = v;
                }
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int n,M,a,b,c;
    scanf("%d%d",&n,&M);
    tol = 0;
    memset(head,-1,sizeof(head));
    while(M--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    SPFA(1,n);
    printf("%d\n",dis[n]);
    return 0;
}