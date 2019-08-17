#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;

struct Edge{
	int u,v,w;
	Edge(){
	}
	Edge(int u,int v,int w):u(u),v(v),w(w){
	}
}edge[MAXN];

bool cmp(Edge a,Edge b){
	return a.w < b.w;
}

int tol = 0;
int F[MAXN];
int find(int x){
	return F[x] == -1 ? x : F[x] = find(F[x]); 
}

void addedge(int u,int v,int w){
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = w;
}

int Kruskal(int N){
	memset(F,-1,sizeof(F));
	int ans = 0;
	int cnt = 0;
	sort(edge,edge+tol,cmp);
	for(int i = 0; i < tol; i++){
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int f1 = find(u);
		int f2 = find(v);
		if(f1 != f2){
			F[f1] = f2;
			ans += w;
			cnt++;
			if(cnt == N-1) break;
		}
	}
	if(cnt < N-1) return -1;
	return ans;
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	while(M--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);
	} 
	cout << Kruskal(N);
	return 0;
}
 
