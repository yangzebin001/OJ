#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct Edge{
	int to,w;
	Edge(int to,int w):to(to),w(w){
	}
};

struct qnode{
	int dis,v;
	qnode(){
	}
	qnode(int dis,int v):dis(dis),v(v){
	}
	bool operator <(const qnode &q)const{
		return dis > q.dis;
	}
};


int dis1[MAXN];
int dis2[MAXN];
bool vis[MAXN];
vector<Edge> G1[MAXN];
vector<Edge> G2[MAXN];

void Dijkstra(int dis[],vector<Edge> G[],int S, int N){
	for(int i = 1; i <= N; i++){
		dis[i] = i == S ? 0 : INF;
		vis[i] = false;
	}
	
	priority_queue<qnode> pq;
	pq.push(qnode(dis[S],S));
	qnode temp;
	while(pq.size()){
		temp = pq.top(); pq.pop();
		if(vis[temp.v]) continue;
		int u = temp.v;
		int d = temp.dis;
		vis[u] = true;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			int d = G[u][i].w;
			if(!vis[v] && dis[v] > dis[u]+d){
				dis[v] = dis[u]+d;
				pq.push(qnode(dis[v],v));
			}
		}
	}	
}

int main(){
	int N,M,S;
	cin >> N >> M >> S;
	for(int i = 0; i <= N; i++){
		G1[i].clear();
		G2[i].clear();
	}
	while(M--){
		int a,b,d;
		cin >>a >>b >>d;
		G1[a].push_back(Edge(b,d));
		G2[b].push_back(Edge(a,d));
	}
	Dijkstra(dis1,G1,S,N);
	Dijkstra(dis2,G2,S,N);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(dis1[i] != INF && dis2[i] != INF){
			ans = max(ans,dis1[i]+dis2[i]);
		}
	}
	cout << ans;
	return 0;
}
