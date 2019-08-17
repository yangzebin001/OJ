#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 500;

struct Edge{
	int to;
	double rate,commission;
	Edge(int _to,double _rate, double _commission):to(_to),rate(_rate),commission(_commission){
	}
};

vector<Edge> G[MAXN];
int num[MAXN];
double dis[MAXN];
bool inq[MAXN];

void init(int N){
	for(int i = 0; i <= N; i++){
		G[i].clear();
	} 
	
}

bool bellman(int S,int N,double V){
	for(int i = 1; i <= N; i++){
		dis[i] = i == S ? V :0.0;
	}
	for(int i = 1; i <= N-1; i++){
		for(int u = 1; u <= N; u++){
			for(int j = 0; j < G[u].size(); j++){
				int v = G[u][j].to;
				double c = G[u][j].commission;
				double r = G[u][j].rate;
				if(dis[v] < ((dis[u]-c)*r)){
					dis[v] = ((dis[u]-c)*r);
				}
			}
		}
	}
	for(int u = 1; u <= N; u++){
		for(int j = 0; j < G[u].size(); j++){
			int v = G[u][j].to;
			double c = G[u][j].commission;
			double r = G[u][j].rate;
			if(dis[v] < ((dis[u]-c)*r)){
				return true;
			}
		}
	}
	return false;
}

bool SPFA(int S, int N,double V){
	for(int i = 1; i <= N; i++){
		dis[i] = i == S ? V :0.0;
		inq[i] = false;
		num[i] = 0;
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
			double r = G[u][i].rate;
			double c = G[u][i].commission;
			if(dis[v] < (dis[u]-c)*r){
				dis[v] = (dis[u]-c)*r;
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

int main(){
	int N,M,S;
	double V;
	cin >> N >> M >> S >> V;
	init(N); 
	for(int i = 0; i < M; i++){
		int from,to;
		double Rab,Cab,Rba,Cba;
		cin >> from >>to >> Rab >> Cab >> Rba >> Cba;
		G[from].push_back(Edge(to,Rab,Cab));
		G[to].push_back(Edge(from,Rba,Cba));
	}
	
	if(bellman(S,N,V)){
		cout << "YES"; 
	}else{
		cout << "NO";
	}
	return 0;
} 
