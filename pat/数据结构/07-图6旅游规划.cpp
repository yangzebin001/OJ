#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define INF 0x3f3f3f
using namespace std;
const int N = 520;

struct E{
	int to;
	int w;
	int cash;
	E(int to, int w, int cash):to(to),w(w),cash(cash){
		
	}
	E(){
	}
};

struct V{
	int dis;
	int cash;
	int v;
	V(int dis, int cash, int v):dis(dis),cash(cash),v(v){
		
	}
	V(){
	}
	friend bool operator < (const V &a,const V &b){
		if(a.dis == b.dis){
			return a.cash < b.cash;
		}
		return a.dis < b.dis;
	}
	
	friend bool operator > (const V &a,const V &b){
		if(a.dis == b.dis){
			return a.cash > b.cash;
		}
		return a.dis > b.dis;
	}
};


int dis[N];
int vis[N];
int cost[N];

vector<E*> G[N];

void InitG(int N){
	for(int i = 0; i < N; i++){
		G[i].clear();
	}
}

void InitDandC(int N){
	for(int i = 0; i < N; i++){
		vis[i] = 0;
		dis[i] = INF;
		cost[i] = INF; 
	}
}

void addEdge(int i,int to, int w, int cash){
	G[i].push_back(new E(to,w,cash));
}

int main(){
	int n,M,S,D;
	cin >> n >> M >> S >> D;
	InitG(n);
	InitDandC(n);
	while(M--){
		int i,to,w,cash;
		cin >> i >> to >> w>> cash;
		addEdge(i,to,w,cash);
		addEdge(to,i,w,cash);
	}
	dis[S] = 0;
	cost[S] = 0;
	priority_queue<V,vector<V>,greater<V> > pq;
	pq.push(V(dis[S],cost[S],S));
	while(!pq.empty()){
		V v = pq.top();
		pq.pop();
		int x = v.v;
		int d = v.dis;
		int ccash = v.cash;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = 0; i < G[x].size(); i++){
			int y = G[x][i]->to;
			int w = G[x][i]->w;
			int cash = G[x][i]->cash;
			if(!vis[y]){
				if(d + w == dis[y]){
					if(ccash + cash < cost[y]){
						cost[y] = ccash + cash;
					}
				}else if(d + w < dis[y]){
					dis[y] = d + w;
					cost[y] = ccash + cash;
					pq.push(V(dis[y],cost[y],y));					
				}
			}
		}
	}
	cout << dis[D] <<" "<< cost[D] << endl;
	return 0;
}

 
