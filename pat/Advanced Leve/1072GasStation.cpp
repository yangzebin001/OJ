#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std; 

const int INF = 0x3f3f3f3f;
const int MAXN = 1050;

int G[MAXN][MAXN];
int dis[MAXN];
bool vis[MAXN];

void Dijkstra(int s,int N){
	for(int i = 1; i <= N; i++){
		vis[i] = false;
		dis[i] = i == s ? 0 : INF;
	}
	for(int i = 1; i <= N; i++){
		int Min = INF;
		int k = -1;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && dis[j] < Min){
				Min = dis[j];
				k = j;
			}
		}
		
		if(k == -1) break;
		vis[k] = true;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && dis[j] > dis[k] + G[k][j]){
				dis[j] = dis[k] + G[k][j];
			}
		}
	}
} 

int toint(string a,int N){
	int ans = 0;
	int index = 0;
	if(a[0] == 'G'){
		index = 1;
	}
	while(index < a.size()){
		ans = ans * 10;
		ans += a[index]-'0';
		index++; 
	}
	return a[0] == 'G' ? ans+N : ans;
}

int main(){
	memset(G,INF,sizeof(G));
	int N,M,K,D;
	scanf("%d%d%d%d",&N,&M,&K,&D);
	while(K--){
		string a,b;
		int dist;
		cin >> a >> b >> dist;
		int aa = toint(a,N);
		int bb = toint(b,N);
		G[aa][bb] = dist;
		G[bb][aa] = dist; 
	}
	int sumdis = INF;
	int mindis = 0;
	int gassation = 0;
	for(int j = 1; j <= M; j++){
		Dijkstra(N+j,N+M);
		bool noreach = false;
		int tsumdis = 0;
		int tmindis = INF;
		for(int i = 1; i <= N; i++){
			if(dis[i] > D) noreach = true;
			tsumdis += dis[i];
			tmindis = min(tmindis,dis[i]);
		}
		if(noreach) continue;
		if(tmindis > mindis){
			sumdis = tsumdis;
			mindis = tmindis;
			gassation = j;
		}else if(tmindis == mindis && tsumdis < sumdis){
			gassation = j;
			sumdis = tsumdis;
		}
		
	} 
	if(gassation != 0){
		printf("G%d\n",gassation);
		printf("%.1f %.1f\n",mindis*1.0,(sumdis*1.0)/N);
	}else{
		printf("No Solution\n");
	}
	return 0;
}
