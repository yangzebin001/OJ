#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 510;
const int INF = 0x3f3f3f3f;
struct Edge{
	int to,cost;
	Edge(int to,int cost):to(to),cost(cost){
	}
	
};
struct qnode{
	int v,d;
	qnode(){
	}
	qnode(int v,int d):v(v),d(d){
	}
	bool operator <(const qnode &r)const{
		return d>r.d;
	}
};

int W[MAXN];
vector<Edge> G[MAXN];
bool vis[MAXN];
int dis[MAXN];
int p[MAXN];
int cont[MAXN];
int team[MAXN];
void Init(int N){
	for(int i = 0; i < N; i++){
		G[i].clear();
	} 
} 

void Dijkstra(int s,int N){
	for(int i = 0; i < N; i++){
		vis[i] = false;
		dis[i] = i == s ? 0 : INF;
		p[i] = i == s ? s : -1;
	}
	priority_queue<qnode> q;
	q.push(qnode(s,dis[s]));
	team[s] = W[s];
	cont[s] = 1;
	qnode temp;
	while(!q.empty()){
		temp = q.top(); q.pop();
		int u = temp.v;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			int cost = G[u][i].cost;
			if(!vis[v] && dis[u] + cost < dis[v]){
				dis[v] = dis[u] +cost;
				q.push(qnode(v,dis[v]));
				cont[v] = cont[u];
				team[v] = W[v] + team[u];
			}else if(!vis[v] && dis[u] + cost == dis[v]){
				cont[v] += cont[u];
				team[v] = max(team[v],W[v] + team[u]);
			}
		}
	}
}

int main(){
	int N,M,S,E;
	scanf("%d%d%d%d",&N,&M,&S,&E);
	for(int i = 0; i < N; i++){
		scanf("%d",&W[i]);
	}
	while(M--){
		int from,to,cost;
		scanf("%d%d%d",&from,&to,&cost);
		G[from].push_back(Edge(to,cost));
		G[to].push_back(Edge(from,cost));
	}
	Dijkstra(S,N);
	printf("%d %d\n",cont[E],team[E]);
	return 0;
	
} 
