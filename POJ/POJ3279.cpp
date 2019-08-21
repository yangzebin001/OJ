#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 20;
const int INF = 0x3f3f3f3f;
int ans[MAXN][MAXN];
int process[MAXN][MAXN];
int anscount = INF;

int m[MAXN][MAXN];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int M,N;


void flip(int x,int y){
    m[x][y] = !m[x][y];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N){
            m[nx][ny] = !m[nx][ny];
        }
    }
}

bool iscomplete(){
    for(int i = 0; i < N; i++){
        if(m[M-1][i]) return false;
    }
    return true;
}

void dfs(){
    int backup[MAXN][MAXN];
    int step = 0;
    for(int k = 0; k < 1 << N; k++){
        memcpy(backup,m,sizeof(m));
        memset(process,0,sizeof(process)); 
        step = 0;
        for(int i = 0 ; i < N; i++){
            if(k>>i & 1){
                flip(0,i);
                step++;
                process[0][i] = !process[0][i];
            }
        }
        for(int i = 0; i < M-1; i++){
            for(int j = 0; j < N; j++){
                if(m[i][j]){
                    flip(i+1,j);
                    step++;
                    process[i+1][j] = !process[i+1][j];
                }
            }
        }
        if(iscomplete()){
            if(step < anscount){
                anscount = step;
                memcpy(ans,process,sizeof(process));
            }
        }
        memcpy(m,backup,sizeof(backup));
    }


}



int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&M,&N);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&m[i][j]);
        }
    }

    dfs();
    if(anscount == INF){
        printf("IMPOSSIBLE");

        return 0;
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            // if(j != 0) printf(" ");
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}