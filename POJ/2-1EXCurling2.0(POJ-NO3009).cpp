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
	//��Ҫ��Ĳ����� ���߱�Ŀǰ��С�Ĳ����� ��������Ҫ��  �˳��� 
	if(step >= 10 || step > minstep){
		return;
	}
	
	//�ĸ���������̽�� 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//��������߽磬������һ���� 
		if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
		//����Ա����յ� 
		if(square[nx][ny] == 3) {
			minstep = min(step+1, minstep);
			return;
		}
		//����Ա���1, ������һ���� 
		if(square[nx][ny] == 1){
			continue;
		} 
		//�ƶ�����ǰ����������ĵ� 
		while(0 <= nx && nx < M && 0 <= ny && ny < N && square[nx][ny] == 0){
			nx += dx[i];
			ny += dy[i]; 
		} 
		//��������߽磬˵��û������1��������һ���� 
		if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
		//���������3�����²������˳��� 
		if(square[nx][ny] == 3) {
			minstep = min(step+1, minstep);
			return;
		}
		
		//������1�����õ���Ϊ0��������ǰһ�����еݹ飬����+1�� 
		if(square[nx][ny] == 1){
			//����һ�� 
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
					//��2����1�� 
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
