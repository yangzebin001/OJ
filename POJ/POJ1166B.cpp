#include<cstdio>
#include<cstring>
using namespace std;

int m[20];
int dx[500];
int button[10][10];
bool f = 1;

bool isF(){
    for(int i = 1; i <= 9; i++){
        if(m[i]) return false;
    }
    return true;
}

void but(int i,int f){
	for(int j =0; j < 7; j++){
		if(button[i][j]){
			if(f)
				m[button[i][j]]++;
			else 
				m[button[i][j]]+=3;
			m[button[i][j]]%=4;
		}
	}
}

void dfs(int v,int k){
    if(isF() & f){
    	int i = 0;
    	while(i < k) printf("%d ",dx[i++]);
    	f = false;
	}
	if(v == 10) return;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < i; j++){
			but(v,1);
			dx[k+j] = v;
		}
		dfs(v+1,k+i);
		for(int j = 0; j < i; j++){
			but(v,0);
		}
		
	} 
//	//一次不按；
//	dfs(v+1,k);
//	//按一次	
//	but(v,1);
//	dx[k] = v;
//	dfs(v+1,k+1);
//	but(v,0);
//	//按二次
//	but(v,1);
//	but(v,1);
//	dx[k] = v;
//	dx[k+1] = v;
//	dfs(v+1,k+2);
//	but(v,0);
//	but(v,0);
//	
//	//按三次
//	but(v,1);
//	but(v,1);
//	but(v,1);
//	dx[k] = v;
//	dx[k+1] = v;
//	dx[k+2] = v;
//	dfs(v+1,k+3);
//	but(v,0);
//	but(v,0);
//	but(v,0);
	
}


int main(){
    freopen("in.txt","r",stdin);
    memset(button,0,sizeof(button));
    button[1][0] = 1,button[1][1] = 2,button[1][2] = 4,button[1][3] = 5;
    button[2][0] = 1,button[2][1] = 2,button[2][2] = 3;
    button[3][0] = 2,button[3][1] = 3,button[3][2] = 5,button[3][3] = 6;
    button[4][0] = 1,button[4][1] = 4,button[4][2] = 7;
    button[5][0] = 2,button[5][1] = 4,button[5][2] = 5,button[5][3] = 6,button[5][4] = 8;
    button[6][0] = 3,button[6][1] = 6,button[6][2] = 9;
    button[7][0] = 4,button[7][1] = 5,button[7][2] = 7,button[7][3] = 8;
    button[8][0] = 7,button[8][1] = 8,button[8][2] = 9;
    button[9][0] = 5,button[9][1] = 6,button[9][2] = 8,button[9][3] = 9;
    
    for(int i = 0; i < 9; i++){
        scanf("%d",&m[i+1]);
    }
    dfs(1,0);

    return 0;
}
