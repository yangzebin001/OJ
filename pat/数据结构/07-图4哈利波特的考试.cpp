#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int G[105][105]; 
int maxn = INF;
bool vis[105];

void Floyd(int n){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
}

int main(){
	int N,M;
	cin>> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			G[i][j] = i == j ? 0 : INF;
		}
	}
	while(M--){
		int a,b,c;
		cin>>a >>b >> c;
		G[a][b] = c;
		G[b][a] = c;
	}
	Floyd(N);
	int ansmin = INF;
	int index = -1;
	for(int i = 1; i <= N; i++){
		int maxn = 0;
		for(int j = 0; j <= N; j++){
			if(maxn < G[i][j]) maxn = G[i][j];
		} 
        if(maxn == INF){
            cout << 0;
            return 0;
        }
		if(ansmin > maxn){
			ansmin = maxn;
			index = i;
		}
	}
    cout << index << " "<<ansmin;
	return 0;
}
