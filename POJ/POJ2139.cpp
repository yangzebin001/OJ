#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 305;
const int INF = 0x3f3f3f3f;

int dis[MAXN][MAXN];

void floyd(int N){

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main(){
	int N,M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			dis[i][j] = (i == j ? 0 :INF);
		}
	}
	while(M--){
		int m;
		cin >> m;
		int data[m];
		for(int i = 0; i < m; i++){
			cin >> data[i];
		}
		for(int i = 0; i < m; i++){
			
			for(int j = i+1; j < m; j++){
				dis[data[i]][data[j]] = 1;
				dis[data[j]][data[i]] = 1;
			}
		}
	}
	floyd(N);
	int mina = INF;
	for(int i = 1; i <= N; i++ ){
		int maxi = 0;
		for(int j = 1; j <= N; j++){
			maxi += dis[i][j];
		}
		mina = min(mina,maxi);
	}
	cout << mina*100/(N-1) << endl;
	return 0;
}
