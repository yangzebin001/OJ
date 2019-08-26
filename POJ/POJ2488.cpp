/*
 * @Author: BeckoninGshy 
 * @Date: 2019-08-24 11:19:39 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2019-08-24 11:19:39 
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
const int MAXM = 100000;
int N,M;
int m[MAXN][MAXN];
int dx[MAXM];
int dy[MAXM];

int dirx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int diry[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int f = 0;
void dfs(int x,int y,int n){
    if(f) return;
    // printf("%d %d\n",x,y);
    dx[n] = x;
    dy[n] = y;
    if(n == N*M-1){
        f = 1;
        for(int i = 0; i < N*M; i++){
            printf("%c%d",('A'+(dy[i])),dx[i]+1);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < 8; i++){
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == 0 && !f){
            m[nx][ny] = 1;
            dfs(nx,ny,n+1);
            m[nx][ny] = 0;
        }
    }
}


int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        scanf("%d%d",&N,&M);
        f = 0;
        printf("Scenario #%d:\n",i+1);
        memset(m,0,sizeof(m));
        m[0][0] = 1;
        // printf("%d %d\n",N,M);
        dfs(0,0,0);
        if(!f) printf("impossible\n");
        if(i != T-1) printf("\n");
    }

    return 0;
}
