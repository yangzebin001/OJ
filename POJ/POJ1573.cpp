/*
 * @Date: 2019-09-10 10:32:44
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-10 11:11:39
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 15;

char MAP[MAXN][MAXN];
int vis[MAXN][MAXN];
int N,M,S;
int step = 1;

pair<int,int> cal(char c){
    if(c == 'N') return make_pair(-1,0);
    if(c == 'E') return make_pair(0,1);
    if(c == 'S') return make_pair(1,0);
    return make_pair(0,-1);
}
void dfs(int x, int y){
    if(x <= 0 || x > N || y <= 0 || y > M){
        printf("%d step(s) to exit\n",step-1);
        return;
    }
    if(vis[x][y]){
        printf("%d step(s) before a loop of %d step(s)\n",vis[x][y]-1,step-vis[x][y]);
        return;
    }
    vis[x][y] = step;
    step++;
    
    
    dfs(x+cal(MAP[x][y]).first,y+cal(MAP[x][y]).second);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&N,&M,&S) && N && M && S){
        step = 1;
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= N; i++){
            scanf("%s",MAP[i]+1);
        }
        dfs(1,S);
        // for(int i = 1; i <= N; i++){
        //     for(int j = 1; j <= M; j++){
        //         printf("%d",vis[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }
    return 0;
}