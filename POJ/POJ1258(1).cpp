#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int INF = 0x3f3f3f3f;
int F[MAXN];

struct Edge{
	int u,v,w;
}edge[MAXN];

int tol = 0;

void addedge(int u,int v, int w){
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = w;
}

bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int find(int x){
	return F[x] == -1 ? x : F[x] = find(F[x]);
}

int Kruskal(int N){
	memset(F,-1,sizeof(F));
	sort(edge,edge+tol,cmp);
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < tol; i++){
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if(t1 != t2){
			F[t1] = t2;
			ans+=w;
			cnt++;
		}
		if(cnt == N-1) break;
	}
	if(cnt < N-1) return -1;
	return ans;
}

int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		tol = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				int w;
				scanf("%d",&w);
				addedge(i,j,w);
				addedge(j,i,w);
			}
		}
		printf("%d\n",Kruskal(N));
	}	
	
	return 0;
}

