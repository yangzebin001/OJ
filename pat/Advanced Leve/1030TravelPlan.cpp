#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 600;
const int INF = 0x3f3f3f3f;

struct Edge{
	int to,dis,cost;
	Edge(int to,int dis,int cost):to(to),dis(dis),cost(cost){
	} 
	Edge(){
	}
}; 
struct qnode{
	int v,d,c;
	qnode(int v,int d,int c):v(v),d(d),c(c){
	} 
	qnode(){
	}
	bool operator <(const qnode &q)const{
		return d > q.d;
	}
};

bool vis[MAXN];
int dis[MAXN];
int cost[MAXN];
int pre[MAXN];

vector<Edge> G[MAXN];

void Init(int N){
	for(int i = 0; i < N; i++)
		G[i].clear(); 
}

void Dijkstra(int S,int N){
	for(int i = 0; i < N; i++){
		dis[i] = i == S ? 0 : INF;
		cost[i] = 0;
		pre[i] = -1;
	}
	priority_queue<qnode> pq;
	pq.push(qnode(S,dis[S],cost[S]));
	qnode temp;
	while(pq.size()){
		temp = pq.top();pq.pop();
		int v = temp.v;
		int d = temp.d;
		int c = temp.c;
		if(vis[v])continue;
		vis[v] = true;
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to;
			int ud = G[v][i].dis;
			int uc = G[v][i].cost;
			if(!vis[u]){
				if(dis[u] > dis[v] + ud){
					dis[u] = dis[v] + ud;
					pre[u] = v;
					cost[u] = cost[v] + uc;
				}else if(dis[u] == dis[v] + ud && cost[u] > cost[v] + uc){
					cost[u] = cost[v] + uc;
					pre[u] = v;
				}
				pq.push(qnode(u,ud,uc));
			}
		}		
	}
}

bool Bellman(int S,int n){
	for(int i = 0; i < n; i ++){
		dis[i] = i == S ? 0 : INF;
		pre[i] = -1;
	}
	for(int i = 0; i < n-1; i++){
		for(int u = 0; u < n; u++){
			for(int j = 0; j < G[u].size(); j++){
				int v =G[u][j].to;
				int d = G[u][j].dis;
				int c = G[u][j].cost;
				if(dis[u] > dis[v] + d){
					dis[u] = dis[v] + d;
					cost[u] = cost[v] + c;
					pre[u] = v;
				}else if(dis[u] == dis[v] + d){
					cost[u] = min(cost[v] + c,cost[u]);
					pre[u] = v;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < G[i].size(); j++){
				int v =G[i][j].to;
				int d = G[i][j].dis;
				if(dis[i] > dis[v] + d){
					return false;
				}
			}
	}
	return true;
}
void showpath(int D){
	if(D == -1) return;
	showpath(pre[D]);
	printf("%d ",D);
}

int main(){
	int N,M,S,D;
	cin >> N >>M >>S >>D;
	Init(N);
	while(M--){
		int f,t,d,c;
		cin >> f >> t >>d >>c;
		G[f].push_back(Edge(t,d,c));
		G[t].push_back(Edge(f,d,c));
	}
	Bellman(S,N);

//	Dijkstra(S,N);

	showpath(D);
	cout << dis[D] << " " << cost[D] <<endl;
	return 0;
} 
