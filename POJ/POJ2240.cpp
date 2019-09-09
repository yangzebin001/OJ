/*
 * @Date: 2019-08-26 16:42:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 18:01:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;
int N;
map<string,int> m;
struct edge{
    int to;
    double dis;
    edge(double _dis,int _to):dis(_dis),to(_to){}
};
vector<edge> G[MAXN];
bool inq[MAXN];
double dis[MAXN];
int num[MAXN];

//判断正环
bool SPFA(int S, int N){
    
    for(int i = 0; i < N; i++){
        inq[i] = false;
        num[i] = 0;
        dis[i] = 0; //判断正环，初始化为0；
    }
    //给源点一个值（任意正数）
    dis[S] = 1; 
    queue<int> q;
    q.push(S);
    inq[S] = true;
    num[S]++;
    while(q.size()){
        int u = q.front(); q.pop();
        inq[u] = false;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].to;
            double d = G[u][i].dis;
            //松弛操作：当前值比松弛之前小的时候，更新
            if(dis[v] < dis[u] * d){
                dis[v] = dis[u] * d;
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    //当松弛了N次之后，还有可能松弛，结束，说明有正环
                    if(num[v] >= N) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    int ca = 1;
    while(scanf("%d",&N) && N){
        m.clear();
        for(int i = 0; i < N; i++) G[i].clear();
        for(int i = 0; i < N; i++){
            char c[1000];
            scanf("%s",c);
            m[string(c)] = i;
        }

        int t;
        scanf("%d",&t);
        for(int i = 0; i < t; i++){
            char c1[1000],c2[1000];
            double d;
            scanf("%s%lf%s",c1,&d,c2);
            
            G[m[string(c1)]].push_back(edge(d,m[string(c2)]));
        }

        printf("Case %d: ",ca++);
        
        if(SPFA(0,N)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}