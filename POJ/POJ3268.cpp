#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int dis1[MAXN];
int dis2[MAXN];
bool vis[MAXN];

int G1[MAXN][MAXN];
int G2[MAXN][MAXN];

void Dijkstra(int dis[],int G[][MAXN],int S,int N){
	for(int i = 0; i <= N; i++){
		dis[i] = i == S ? 0 : INF;
		vis[i] =false;
	}
	
	for(int i = 1; i <= N; i++){
		int k = -1;
		int Min = INF;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && dis[j] < Min){
				Min = dis[j];
				k = j;
			}
		}
		if(k == -1) break;
		vis[k] = true;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && dis[j] > dis[k]+G[k][j]){
				dis[j] = dis[k]+G[k][j];
			}
		}
	}
}


int main(){
	int N,M,S;
	cin >> N >> M>> S;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			G1[i][j] = INF;
			G2[i][j] = INF;
		}
	}
	while(M--){
		int a,b,w;
		cin >> a >>b >>w;
		G1[a][b] = w;
		G2[b][a] = w;
	}
	Dijkstra(dis1,G1,S,N);
	Dijkstra(dis2,G2,S,N);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(dis1[i] != INF && dis2[i] != INF)
			ans = max(ans,dis1[i]+dis2[i]);
	}
	cout <<ans;
	return 0;
}
