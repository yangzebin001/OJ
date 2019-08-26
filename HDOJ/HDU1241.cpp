#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 200;

char m[MAXN][MAXN];
int N,M;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

int dfs(int x,int y){
    m[x][y] = '*';
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '@'){
            dfs(nx,ny);
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M) && N && M){
        for(int i = 0; i < N; i++){
            scanf("%s",m[i]);
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(m[i][j] == '@'){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}