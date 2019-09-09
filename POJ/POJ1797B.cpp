/*
 * @Date: 2019-08-29 10:27:45
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-29 15:23:43
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1005;

struct node{
	int u,v,w;
	node(){}
	node(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	}
	bool operator<(const node &tt)const{
		return w > tt.w;
	}
}Edge[MAXN*MAXN];
int F[MAXN];

int getfather(int x){
	return F[x] == x ? x : F[x] = getfather(F[x]);
}

int main(){
	freopen("in.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int k = 1; k <= T; k++){
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= M; i++){
			scanf("%d%d%d",&Edge[i].u, &Edge[i].v, &Edge[i].w);
		}
		int ans = 0;
		sort(Edge+1,Edge+1+M);
		for(int i = 1; i <= N; i++) F[i] = i;
		for(int i = 1; i <= M; i++){
			int a = getfather(Edge[i].u);
			int b = getfather(Edge[i].v);
			if(getfather(1) == getfather(N)) break;
			if(a != b){
				F[a] = b;
				ans = Edge[i].w; 
			}
		}
		printf("Scenario #%d:\n",k);
		printf("%d\n\n",ans);
	}
	return 0;
}

