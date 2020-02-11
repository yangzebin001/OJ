/*
 * @Date: 2020-01-26 12:47:36
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-26 12:57:07
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int M[110][110],vis[110][110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ans;
bool isvaild(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dfs(int x,int y){
    if(vis[x][y]) return vis[x][y];
    int n = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isvaild(nx,ny) && M[nx][ny] < M[x][y]){
            n = max(n,dfs(nx,ny) + 1);
        }
    }
    return vis[x][y] = n;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&M[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans,dfs(i,j));
        }
    }
    cout << ans;
    return 0;
}