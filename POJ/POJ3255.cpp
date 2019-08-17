#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct edge{
	int to,w;
	edge(int to,int w):to(to),w(w){
	}
};
struct qnode{
	int to,dis;
	qnode(int to, int dis):to(to),dis(dis){
	}
	qnode(){
	}
	bool operator <(const qnode &q)const{
		return dis>q.dis;
	}
};
const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
int lowcost[MAXN];
int secost[MAXN];
vector<edge> G[MAXN];

void Dijkstra(int S,int N){
	for(int i = 1; i <= N; i++){
		lowcost[i] = i == S ? 0 :INF;
		secost[i] = INF;
	}
	priority_queue<qnode> pq;
	pq.push(qnode(S,lowcost[S]));
	qnode temp;
	while(pq.size()){
		temp = pq.top();pq.pop();
		int u = temp.to;
		int dis = temp.dis;
		//�����ǰ·���ȴζ�·�����󣬲��������ģ�����ֱ�������� 
		if(dis > secost[u]) continue;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			int w = G[u][i].w;
			int d2 = dis + w;
			//������ǰ���·���͸��º�����·�� �����ڸ��´ζ�·���� 
			if(lowcost[v] > d2){
				swap(d2,lowcost[v]);
				pq.push(qnode(v,lowcost[v]));
			}
			//�ҵ��ζ�·������һ��Ҫ�ٽ��ζ�·��push�����У�Ϊ����һ�������ζ�·���� 
			if(d2 > lowcost[v] && d2 < secost[v]){
				secost[v] = d2;
				pq.push(qnode(v,secost[v]));
			}
		}
	}
}

void init(int N){
	for(int i = 1; i <= N; i++){
		G[i].clear();
	} 
} 
int main(){
	int N,R;
	scanf("%d%d",&N,&R);
	init(N);
	for(int i = 0; i < R; i++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		G[a].push_back(edge(b,d));
		G[b].push_back(edge(a,d));
	} 
	Dijkstra(1,N);
	printf("%d",secost[N]);
	return 0;
} 
