/*
 * @Date: 2019-08-31 09:45:51
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-31 10:31:30
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 40000;
const int INF = 0x3f3f3f3f;

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

vector<vector<qnode> > G;
int vis[MAXN];
// int dis[MAXN];

int main(){
    //freopen("in.txt","r",stdin);
    int N,M;
    scanf("%d%d",&N,&M);
    qnode temp;
    G.clear();
    G.resize(N+1);
    for(int i = 0; i < M; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        temp.v = b;
        temp.d = c;
        G[a].push_back(temp);
    }

    memset(vis,0,sizeof(vis));
    priority_queue<qnode> pq;
    pq.push(qnode(1,0));
    while(pq.size()){
        temp = pq.top(); pq.pop();
        // dis[temp.v] = temp.d;
        if(vis[temp.v]) continue;
        vis[temp.v] = 1;
        if(temp.v == N) break;
        for(int i = 0,j =  G[temp.v].size(); i < j; i++){
           qnode p;
           p.v = G[temp.v][i].v;
           if(vis[p.v]) continue;
           p.d = temp.d+G[temp.v][i].d;
           pq.push(p);
        }
    }
    
    printf("%d\n",temp.d);
    return 0;
}