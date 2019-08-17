#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 300;
const int INF = 0x3f3f3f3f;
int G[MAXN][MAXN];
int D[MAXN];
int indegree[MAXN];
bool topsort(int N){
	queue<int> q;
	int cont = 0;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		int v = q.front();q.pop();
		//处理当前的 入度为零的结点。 
		//入度为零的结点数，如果处理完之后没有到总结点数，说明没有终点。（有回路） 
		cont++;
		//遍历与该入度为零的结点连接的结点。 
		for(int i = 0; i < N; i++){
			//有效边。 
			if(G[v][i] != INF){
				//更新权值。 
				D[i] = max(D[i],D[v]+G[v][i]);
				//入度为零可以进队列。 
				if(--indegree[i] == 0)
					q.push(i);
			}
		}
	}
	if(cont != N){
		return false;
	}
	return true;
}

int main(){
	int N, M;
	cin >> N >> M;
	memset(G,INF,sizeof(G));
	while(M--){
		int a,b,c;
		cin >> a >> b >>c;
		G[a][b] = c;
		indegree[b]++;
	}
	
	if(!topsort(N))
		cout << "Impossible" << endl;
	else{
		
		int ans = 0;
		for(int i = 0; i < N; i++) ans = max(ans,D[i]);
		cout << ans;
	}
	return 0;
}
