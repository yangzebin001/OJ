/*
 * @Date: 2020-01-22 19:01:34
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 19:35:37
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int x,y,step;
    node(){};
    node(int _x,int _y, int _step):x(_x),y(_y),step(_step){};
};
int M[410][410];
bool vis[410][410];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,-2,-1,1,2};
int main(){
    memset(M,-1,sizeof(M));
    memset(vis,false,sizeof(vis));
    int n,m;
    int x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    x--,y--;
    int cnt = 0;
    queue<node> q;
    q.push(node(x,y,0));
    while(q.size()){
        node now = q.front();q.pop();
        if(M[now.x][now.y] != -1) continue;
        M[now.x][now.y] = now.step;
        // vis[now.x][now.y] = true;
        // cout << now.x << " " << now.y << endl;
        for(int i = 0; i < 8; i++){
            int nx = dx[i]+now.x;
            int ny = dy[i]+now.y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && M[nx][ny] == -1){
                // M[nx][ny] = true;
                q.push(node(nx,ny,now.step+1));
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%-5d",M[i][j]);
        }
        printf("\n");
    }
    return 0;
}