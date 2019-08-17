#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX_N = 20;

char field[MAX_N][MAX_N+1];

int N, M;
int sx, sy;
int cot = 0;

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

void dfs(int x, int y){
	//将该点标记 
	field[x][y] = '#';
	cot++;
	int nx,ny;
	//四个方向搜索 
	for(int i = 0; i < 4; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		//只要不是墙壁，就继续递归。 
		if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '#'){
			dfs(nx,ny);
		}
	}
	return ;
}

int main(){
	scanf("%d%d",&M,&N);
	while(M){
		cot = 0;
			getchar();
		for(int i = 0; i < N; i++){
			char c;
			int j = 0;
			while((c = getchar()) != '\n' && c != EOF && j < M){
				field[i][j] = c;
				//记录开始位置 
				if(c == '@'){
					sx = i;
					sy = j;
				}
				j++;
			}
			field[i][j] = '\0';
		}
		
		dfs(sx,sy);
		printf("%d\n",cot);
		scanf("%d%d",&M,&N);
	}

	return 0;
}


