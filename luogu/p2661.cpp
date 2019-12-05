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
int currvis[MAXN];
inline void dfs(int x,int d){
	if(vis[x]) return;
	if(currvis[x]) ans = min(ans,d-currvis[x]);
	else{
		currvis[x] = d;
		dfs(G[x],d+1);
		vis[x] = 1;
        currvis[x] = 0;
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		int b;
		scanf("%d",&b);
		G[i] = b;
	}
	for(int i = 1; i <= n; i++){
		//将剩下的没遍历过的遍历一下
		if(!vis[i])
			dfs(i,0);
	}
	printf("%d",ans);
	return 0;
} 
