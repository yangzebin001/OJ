#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 520;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int cash[MAXN][MAXN];
int lowcost[MAXN];
int lowcash[MAXN];

void Dijkstra(int cost[][MAXN],int lowcost[],int cash[][MAXN],int lowcash[],int n,int beg){
	for(int i = 0; i < n; i++){
		lowcost[i] = INF;
		lowcash[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	lowcost[beg] = 0;
	lowcash[beg] = 0;
	for(int j = 0; j < n; j++){
		int k = -1;
		int Min = INF;
		for(int i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] < Min){
				Min = lowcost[i];
				k = i;
			}
			if(k != -1 && !vis[i] && lowcost[i] == Min && lowcash[i] < lowcash[k]){
				k = i;
			}
		}
		if(k == -1)break;
		vis[k] = true;
		for(int i = 0; i < n; i++){
			if(!vis[i] && lowcost[k] + cost[i][k] < lowcost[i]){
				lowcost[i] = lowcost[k] + cost[i][k];
				lowcash[i] = lowcash[k] + cash[i][k];
				pre[i] = k;
			}else if(!vis[i] && lowcost[k] + cost[i][k] == lowcost[i] && lowcash[k] + cash[i][k] <  lowcash[i]){
				lowcash[i] = lowcash[k] + cash[i][k];
			}
		}
	}
}
int main(){
	int N,M,S,D;
	cin >> N >> M >> S >> D;
	memset(cost,INF,sizeof(cost));
	memset(cash,INF,sizeof(cash));
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < N; j++){
//			cost[i][j] = INF;
//			cash[i][j] = INF;
//		}
//	}
	while(M--){
		int s,e,w,c;
		cin >>s >>e >>w >> c;
		cost[s][e] = w;
		cost[e][s] = w;
		cash[s][e] = c;
		cash[e][s] = c;
	} 
	Dijkstra(cost,lowcost,cash,lowcash,N,S);
	cout << lowcost[D] << " " << lowcash[D] << endl;
	return 0;
} 
