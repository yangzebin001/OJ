#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX_N = 100;
char field[MAX_N][MAX_N+1];

int N, M;

void dfs(int x, int y){
	field[x][y] = '.';
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			//九个方向依次移动 
			int nx = dx+x, ny = dy+y;
			//判断边界与是否有积水 
			if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx,ny); 
		}
	}
	return ;
}

int main(){
	scanf("%d%d",&N,&M);
	getchar();
	for(int i = 0; i < N; i++){
		char c;
		int j = 0;
		while((c = getchar()) != '\n' && c != EOF){
			field[i][j++] = c;
			
		}
	}	
		
	int res = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(field[i][j] == 'W'){
				dfs(i,j);
				res++;
			} 
		}
	}
	
	printf("%d",res);
	
	return 0;
}
