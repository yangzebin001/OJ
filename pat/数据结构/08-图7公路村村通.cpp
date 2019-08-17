#include<iostream>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5010;

int G[MAXN][MAXN]; 
bool vis[MAXN];
int lowc[MAXN];

void init(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			G[i][j] = INF;
		}
		lowc[i] = INF;
	}
}

int Prim(int n){
	int ans = 0;
	memset(vis,false,sizeof(vis));
	vis[1] = true;
	for(int i = 2; i <= n; i++) lowc[i] = G[1][i];
	for(int i = 2; i <= n; i++){
		int minc = INF;
		int p = -1;
		for(int j = 1; j <= n; j++){
			if(!vis[j]&&minc > lowc[j]){
				minc = lowc[j];
				p = j;
			}
		}
		if(minc == INF) return -1;
		ans += minc;
		vis[p] = true;
		for(int j = 1; j <= n; j++){
			if(!vis[j]&&lowc[j] > G[p][j])
				lowc[j] = G[p][j];
		}
	}
	return ans;
}

int main(){
	int N,M;
	cin >> N >> M;
	init(N);
	while(M--){
		int a, b, cost;
		cin >> a >> b >>cost;
		G[a][b] = cost;
		G[b][a] = cost; 
	} 
	int ans = Prim(N);
	cout << ans;
	return 0;
} 
