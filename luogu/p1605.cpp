/*
 * @Date: 2020-01-25 19:11:37
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 19:19:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[10][10];
int n,m,t;
int sx,sy,ex,ey;
int dx[5] = {0,1,0,-1};
int dy[5] = {-1,0,1,0};
bool vaild(int x,int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int ans = 0;
void dfs(int x,int y){
    if(x == ex && y == ey){
        ans++;
        return;
    }
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(vaild(nx,ny) && !vis[nx][ny]){
            dfs(nx,ny);
        }
    }
    vis[x][y] = 0;
}

int main(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> ex >> ey;
    for(int i = 0; i < t; i++){
        int x,y;
        cin >> x >> y;
        vis[x][y] = 2;
    }
    dfs(sx,sy);
    cout << ans;
    return 0;
}