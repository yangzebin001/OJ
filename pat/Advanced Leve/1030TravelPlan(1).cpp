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


bool inq[MAXN];
int dis[MAXN];
int cost[MAXN];
int pre[MAXN];
int num[MAXN];

vector<Edge> G[MAXN];

void Init(int N){
	for(int i = 0; i < N; i++)
		G[i].clear(); 
}

bool SPFA(int S,int N){
	for(int i = 0; i < N; i++){
		dis[i] = i == S ? 0 : INF;
		pre[i] = -1;
		num[i] = 0;
		cost[i] = 0;
		inq[i] = false;
	}
	queue<int> q;
	
	q.push(S);
	inq[S] = true;
	num[S]++;
	while(q.size()){
		int u = q.front();q.pop();
		inq[u] = false;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			int d = G[u][i].dis;
			int c = G[u][i].cost;
			if(dis[v] > dis[u] + d){
				dis[v] = dis[u] + d;
				pre[v] = u;
				cost[v] = cost[u] + c;
				if(!inq[v]){
					q.push(v);
					num[v]++;
					inq[v] = true;
					if(num[v] >= N) return false;
				}
			}else if(dis[v] == dis[u] + d){
				if(cost[v] > cost[u] + c){
					cost[v] = cost[u] + c;
					pre[v] = u;
				}
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
	SPFA(S,N);
	;

	showpath(D);
	cout << dis[D] << " " << cost[D] <<endl;
	return 0;
} 
