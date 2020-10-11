/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 16:00:33 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 16:26:41
 */
#include<bits/stdc++.h>
using namespace std;
int vis[10][10];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int ans = 0;

void dfs(int x, int y){
    if(x == 0 || y == 0 || x == 6 || y == 6){
        ans++;
        return;
    }
    vis[x][y] = vis[6-x][6-y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx <= 6 && ny >= 0 && ny <= 6 && !vis[nx][ny]){
            dfs(nx,ny);
        }
    }
    vis[x][y] = vis[6-x][6-y] = 0;
}

int main(){
    dfs(3,3);
    printf("%d",ans/4); //如果两个状态经过魔方的整体旋转后，各个面的颜色都一致，则认为是同一状态。 
    //所以要/4
    return 0;
}