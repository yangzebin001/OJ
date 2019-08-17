#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 503;
const int INF = 0x3f3f3f3f;



int dis[MAXN][MAXN];


bool floyd(int N){
	
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				if(dis[i][j] > dis[i][k]+dis[k][j]){
					
					dis[i][j] = dis[i][k]+dis[k][j];
					if(i == j && dis[i][j] < 0 ) return true;
				}
	return false;
}

void init(int N){
	
	
}
int main(){
	int F;
	scanf("%d",&F);
	while(F--){
		int N,M,W;
		scanf("%d%d%d",&N,&M,&W);
		memset(dis,INF,sizeof(dis));
		while(M--){
			int a,b,d;
			scanf("%d%d%d",&a,&b,&d);
			dis[a][b] = min(dis[a][b],d);
			dis[b][a] =  min(dis[b][a],d);
		}
		int S,E,T;
		while(W--){
			scanf("%d%d%d",&S,&E,&T);
			dis[S][E] = -T;
		}

		if(floyd(N)) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
