#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

struct Edge{
	int to,cost;
	Edge(int to, int cost):to(to),cost(cost){
	}
	Edge(){
	}
};
struct qnode{
	int u,dis;
	qnode(int u,int dis):u(u),dis(dis){
	}
	qnode(){
	}
	bool operator <(const qnode &q)const{
		return dis > q.dis;
	}
};

vector<Edge> G[MAXN];
bool vis[MAXN];
int dis[MAXN];

void Dijkstra(int s, int N){
	for(int i = 1; i <= N; i++) dis[i] = i == s ? 0 : INF;
	priority_queue<qnode> pq;
	dis[s] = 0;
	pq.push(qnode(s,dis[s]));
	qnode temp;
	while(!pq.empty()){
		temp = pq.top();pq.pop();
		if(vis[temp.u]) continue;
		vis[temp.u] = true;
		for(int i = 0; i < G[temp.u].size(); i++){
			int v = G[temp.u][i].to;
			int cost = G[temp.u][i].cost;
			if(!vis[v] && dis[v] > dis[temp.u] + cost){
				dis[v] = dis[temp.u] + cost;
				pq.push(qnode(v,dis[v]));
			}
		}
	}
}



int main(){
	int T,N;
	cin >> T >> N;
	while(T--){
		int a,b,cost;
		cin >> a>> b >> cost;
		int i;
		for(i = 0; i < G[a].size(); i++){
			if(G[a][i].to == b){
				G[a][i].cost = min(G[a][i].cost,cost);
				break;
			}
		}
		if(i == G[a].size()){
			G[a].push_back(Edge(b,cost));
		}
		for(i = 0; i < G[b].size(); i++){
			if(G[b][i].to == a){
				G[b][i].cost = min(G[b][i].cost,cost);
				break;
			}
		}
		if(i == G[b].size()){
			G[b].push_back(Edge(a,cost));
		}
	}
	Dijkstra(1,N);
	cout << dis[N];
	return 0;
} 
