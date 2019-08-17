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
		//����ǰ�� ���Ϊ��Ľ�㡣 
		//���Ϊ��Ľ���������������֮��û�е��ܽ������˵��û���յ㡣���л�·�� 
		cont++;
		//����������Ϊ��Ľ�����ӵĽ�㡣 
		for(int i = 0; i < N; i++){
			//��Ч�ߡ� 
			if(G[v][i] != INF){
				//����Ȩֵ�� 
				D[i] = max(D[i],D[v]+G[v][i]);
				//���Ϊ����Խ����С� 
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
