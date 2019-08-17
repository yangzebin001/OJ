#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50015;
const int INF = 0x3f3f3f3f;

struct Edge{
	int from,to,w;
	Edge(int from,int to, int w){
		from = from;
		to = to;
		w = w;
	} 
	Edge(){
	}
}edge[MAXN];
int F[MAXN];
bool cmp(const Edge a,const Edge b){
	return a.w < b.w;
}

int tol = 0;

int find(int x){
	return F[x] == -1 ? x : F[x] = find(F[x]);
}
void init(int N){
	tol = 0;
	memset(F,-1,sizeof F);
}


int Kruskal(){
	int ans = 0;
	sort(edge,edge+tol,cmp);
	for(int i = 0; i < tol; i++){
		int from = edge[i].from;
		int to = edge[i].to;
		int w = edge[i].w;
		int a = find(from);
		int b = find(to);
		if(a != b){
			F[a] = b;
			ans+=w;
		}
	}
	return ans;
}

int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int N,M,R;
		scanf("%d%d%d",&N,&M,&R);
		init(N+M);
		for(int i = 0; i < R; i++){
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			edge[tol].from = a;
			edge[tol].to = b+N;
			edge[tol].w = -w;
			tol++;
		} 
		printf("%d\n",10000*(N+M) + Kruskal());
	}
	return 0;
} 
