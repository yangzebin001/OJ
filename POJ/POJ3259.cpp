#include<iostream>
#include<algorithm>
#include<vector> 
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 100000;
const int INF = 1000002;

struct Edge{
	int to,w;
	Edge(int to,int w):to(to),w(w){} 
};

int dis[MAXN];
int num[MAXN];
bool inq[MAXN];
vector<Edge> G[MAXN];

//void floyd(int N){
//	for(int k = 1; k <= N; k++)
//		for(int i = 1; i <= N; i++)
//			for(int j = 1; j <= N; j++)
//				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
//}

bool SPFA(int S,int N){
	for(int i = 1; i <= N; i++) dis[i] = i == S ? 0 : INF;
	memset(inq,false,sizeof(inq));
	memset(num,0,sizeof(num));
	queue<int> q;
	q.push(S);
	num[S]++;
	inq[S] = true;
	while(q.size()){
		int u = q.front(); q.pop();
		inq[u] = false;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			int w = G[u][i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v] >= N) return true;
				}
			}
		}
	}
	return false;
}

bool bellman(int S, int N){
	for(int i = 1; i <= N; i++) dis[i] = i == S ? 0 : INF;
	memset(inq,false,sizeof(inq));
	memset(num,0,sizeof(num));
	for(int i = 1; i < N; i++){
		for(int u = 1; u <= N; u++){
			for(int j = 0; j < G[u].size(); j++){
				int v = G[u][j].to;
				int w = G[u][j].w;
				if(dis[v] > dis[u]+w){
					dis[v] = dis[u] + w;
				}
			}
		}
	}
	for(int u = 1; u <= N; u++){
		for(int j = 0; j < G[u].size(); j++){
			int v = G[u][j].to;
			int w = G[u][j].w;
			if(dis[v] > dis[u]+w){
				return true;
			}
		}
	}
	return false;
}


void init(int N){
	for(int i = 1; i <= N; i++)
		G[i].clear();
	
}
int main(){
	int F;
	cin >> F;
	while(F--){
		int N,M,W;
		cin >> N >> M >> W;
		init(N);
		while(M--){
			int a,b,d;
			cin >> a >> b >>d;
			G[a].push_back(Edge(b,d));
			G[b].push_back(Edge(a,d));
		}
		int S,E,T;
		while(W--){
			cin >> S >> E >> T;
			int flag = 0;
			for(int i = 0; i < G[S].size(); i++){
				if(G[S][i].to == E){
					G[S][i].w = -T;
					flag = 1;
				}
			}
			if(flag == 0)G[S].push_back(Edge(E,-T));
		}
//		for(int i = 1; i <= N; i++){
//			for(int j = 0; j < G[i].size(); j++){
//				cout << "( "<< G[i][j].to << " " << G[i][j].w << ") ";
//			}
//			cout << endl;
//		}
		if(bellman(S,N)) cout << "YES" << endl;
		else cout << "NO" <<endl;
		
	}
	return 0;
}
