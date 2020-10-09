#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//int idx[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
int vis[12] = {0,0,0,0,0,0,0,1,1,1,1,1};
int viscp[12] = {0,0,0,0,0,0,0,1,1,1,1,1};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0}; 

int toone(int x, int y){
	return x*4+y;
} 

int ans = 0;
void dfs(int x, int y){
	if(!vis[toone(x,y)]) return;
	vis[toone(x,y)] = 0;
	for(int i = 0; i < 4; i++){
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx >= 0 && nx < 3 && ny >= 0 && ny < 4){
			dfs(nx,ny);
		}
	}
}

int main(){
	int res = 0;
	do{
//		for(int i = 0; i < 12; i++){
//			printf("%d ", vis[i]);
//		}
//		printf("\n");
		memcpy(viscp, vis, sizeof(vis));
		int ans = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 4; j++){
				if(vis[toone(i,j)]){
					dfs(i,j);
					ans++;
				}
			}
		} 
		
		memcpy(vis, viscp, sizeof(vis));
		if(ans == 1) res++;
	}while(next_permutation(vis,vis+12));
	printf("%d",res);
	return 0;
}
