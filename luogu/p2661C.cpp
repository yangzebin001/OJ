#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 300000;
const int INF = 0x3f3f3f3f;
int G[MAXN]; 
int ans = INF;
int vis[MAXN];
int ind[MAXN];
inline void dfs(int x,int d){
	if(vis[x]){ ans = min(ans,d-vis[x]); return;}
	vis[x] = d;
	dfs(G[x],d+1);
}


int main(){
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		int b;
		scanf("%d",&b);
		G[i] = b;
		ind[b]++;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			int k = i;
			while(ind[k] == 0){
				vis[k] = 1;
				--ind[G[k]];
				k = G[k];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	printf("%d",ans);
	return 0;
} 
