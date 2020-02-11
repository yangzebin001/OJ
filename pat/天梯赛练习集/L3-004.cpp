/*
 * @Date: 2020-01-29 19:08:40
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 19:49:15
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1300;
const int MAXM = 150;
const int MAXZ = 70;
int M[MAXZ][MAXN][MAXM];
int vis[MAXZ][MAXN][MAXM];
int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};
int n,m,l,t;
bool judge(int z,int x, int y){
    return z >= 0 && z < l && x >= 0 && x < n && y >= 0 && y < m;
}
int cnt,ans;
struct node{
    int x,y,z;
    node(){};
    node(int _z,int _x,int _y):z(_z),x(_x),y(_y){};
};
void bfs(int z, int x, int y){
    queue<node> q;
    q.push(node(z,x,y));
    node c;
    vis[z][x][y] = 1;
    while(!q.empty()){
        cnt++;
        c = q.front(); q.pop();
        x = c.x;
        y = c.y;
        z = c.z;
        M[z][x][y] = 0;
        for(int i = 0; i < 6; i++){
            int nz = dz[i]+z;
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(judge(nz,nx,ny) && M[nz][nx][ny] && !vis[nz][nx][ny]){
                q.push(node(nz,nx,ny));
                vis[nz][nx][ny] = 1;
            }
        }
    }
}
int main(){
    cin >> n >> m >> l >> t;
    for(int a = 0; a < l; a++){
        for(int b = 0; b < n; b++){
            for(int c = 0; c < m; c++){
                cin >> M[a][b][c];
            }
        }
    }
    for(int a = 0; a < l; a++){
        for(int b = 0; b < n; b++){
            for(int c = 0; c < m; c++){
                if( M[a][b][c] && !vis[a][b][c]){
                    cnt = 0;
                    bfs(a,b,c);
                    if(cnt >= t){
                        ans += cnt;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
    
}