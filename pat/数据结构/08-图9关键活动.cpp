#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 200;
const int INF = 0x3f3f3f3f;

struct Edge{
	int to,w;
	Edge(int to,int w):to(to),w(w){
	}
};

vector<Edge> G[MAXN];
int inDegree[MAXN];
int vl[MAXN];
int ve[MAXN]; 

void Init(int N){
	for(int i = 0; i <= N; i++){
		G[i].clear();
	}
} 

stack<int> topOrder;

bool topsort(int N){
	queue<int> q;
	for(int i = 1; i <= N; i++){
		if(inDegree[i] == 0) q.push(i);
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i = 0; i < G[u].size(); i++){
			int v= G[u][i].to;
			inDegree[v]--;
			if(inDegree[v] == 0) q.push(v);
			if(ve[u] + G[u][i].w > ve[v]){
				ve[v] = ve[u] + G[u][i].w;
			}
		}
	}
	return topOrder.size() == N;
}
void CriticalPath(int N){
	bool ans = topsort(N);
	
	int maxlength = 0;
	for(int i = 1; i <= N; i++){
		maxlength = max(maxlength,ve[i]);
	}
	if(ans == false){
		cout << 0 << endl;
		return;
	}else{
		cout << maxlength << endl;
	}
	fill(vl,vl+N+1,maxlength);
	while(topOrder.size()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			if(vl[v]-G[u][i].w < vl[u]){
				vl[u] = vl[v]-G[u][i].w;
			}
		}
	}
	
	for(int u = 1; u <= N; u++){
		for(int j = G[u].size()-1; j >= 0; j--){
			int v = G[u][j].to,w = G[u][j].w;
			int e = ve[u],l = vl[v]-w;
			if(e == l){
				cout << u << "->" << v << endl;
			}
		}
	} 
}


int main(){
	int N,M;
	cin >> N >> M;
	while(M--){
		int a,b,c;
		cin >> a >>b >>c;
		G[a].push_back(Edge(b,c));
		inDegree[b]++;
	}
	CriticalPath(N);
	;
	return 0;
}
