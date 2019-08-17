#include<stdio.h>
#include<algorithm>

using namespace std;
int square[22][22];

int sx,sy,gx,gy;
int step = 0;
int minstep = 10E8;

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
int N,M;

void dfs(int x, int y, int step){
	//比要求的步数大 或者比目前最小的步数大 都不满足要求  退出。 
	if(step >= 10 || step > minstep){
		return;
	}
	
	//四个方向依次探测 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//如果超出边界，继续下一方向 
		if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
		//如果旁边是终点 
		if(square[nx][ny] == 3) {
			minstep = min(step+1, minstep);
			return;
		}
		//如果旁边是1, 继续下一方向 
		if(square[nx][ny] == 1){
			continue;
		} 
		//移动到当前方向不再是零的点 
		while(0 <= nx && nx < M && 0 <= ny && ny < N && square[nx][ny] == 0){
			nx += dx[i];
			ny += dy[i]; 
		} 
		//如果超出边界，说明没有碰到1，继续下一方向 
		if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
		//如果碰到了3，更新步长并退出。 
		if(square[nx][ny] == 3) {
			minstep = min(step+1, minstep);
			return;
		}
		
		//碰到了1，将该点置为0，继续将前一步进行递归，步长+1。 
		if(square[nx][ny] == 1){
			//后退一步 
			square[nx][ny] = 0;
			dfs(nx-dx[i], ny - dy[i], step+1);
			square[nx][ny] = 1;
		} 
		
	}
	
}

int main(){

	scanf("%d%d",&N,&M);
	while(N){
		step = 0;
		minstep = 10E8;
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				int a;
				scanf("%d",&a);
				square[i][j] = a;
				if(a == 2){
					sx = i;
					sy = j;
					//把2当做1。 
					square[i][j] = 0;
				}else if(a == 3){
					gx = i;
					gy = j;
				}
			}
		}
		
		dfs(sx,sy,step);
		if(minstep == 10E8){
			printf("-1\n");
		}else{
			printf("%d\n",minstep);
		}
		scanf("%d%d",&N,&M);
	}
	
	return 0;
}
