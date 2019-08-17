#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 200;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,cost;
    Edge(){};
    Edge(int a,int b){
        to = a;
        cost = b;
    };
};

struct qnode{
    int v,cost;
    qnode(int _v, int _cost){
        v = _v;
        cost = _cost;
    }
    qnode(){}
    bool operator <(const qnode &b)const{
        return cost > b.cost;
    }
};
vector<Edge> G[MAXN];

int coin[MAXN]; //价值多少金币 
int dis[MAXN];	//最少优惠 
int vis[MAXN];	
int pos[MAXN];  //等级 
int M,N;
int ans;
 void Dijkstra(int S,int N){
 	for(int i = 1; i <= N; i++){
 		dis[i] = S== i ? 0 : INF;
	 }
     priority_queue<qnode> pq;
     pq.push(qnode(S,dis[S]));
     qnode temp;
     while(pq.size()){
         temp = pq.top();pq.pop();
         int u = temp.v;
         if(vis[u])continue;
         vis[u] = 1;
         for(int i = 0; i < G[u].size(); i++){
             int v = G[u][i].to;
             int vc = G[u][i].cost;
             if(!vis[v] && dis[v] > dis[u] + vc){
                dis[v] = dis[u] + vc;	
                //更新答案 
                ans = min(ans,dis[v] + coin[v]);
                pq.push(qnode(v,dis[v]));
             }
         }
     }
//     for(int i = 1; i <= N; i++){
//     	ans = min(ans,dis[i] + coin[i]);		
//	 } 
 }

void init(int N){
	for(int i = 0; i <= N; i++){
		G[i].clear();
	}
} 

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d %d",&M,&N);
    init(N);
    for(int i = 1; i <= N; i++){
        int c,r,n;
        scanf("%d%d%d",&c,&r,&n);
        coin[i] = c;
        pos[i] = r;

        for(int j = 1; j <= n; j++){
            int t,cost;
            scanf("%d%d",&t,&cost);
            G[i].push_back(Edge(t,cost));
        }
    }
    //设最大值为起始值 
    ans = coin[1];
    for(int i = 0; i <= M; i++){
    	//更新每个点是否在当前区间内 
    	for(int j = 1; j <= N; j++){
    		if(pos[j] >= pos[1]-M+i && pos[j] <= pos[1]+i) vis[j] = 0;
    		else vis[j] = 1;
		}
		//求一下当前区间的最短路。 
		Dijkstra(1,N);
	}
    printf("%d",ans);
    return 0;
}
