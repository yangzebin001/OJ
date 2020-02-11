/*
 * @Date: 2020-01-29 22:10:26
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 22:31:25
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1510;
char M[MAXN][MAXN];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n,m;
struct node{
    int x,y;
    node(){};
    node(int _x, int _y):x(_x),y(_y){};
};
bool judge(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool jud(){
    for(int i = 0; i < n; i++){
        if(M[i][0] == 'S' && M[i][0] == M[i][m-1]) return true;
    }
    for(int i = 0; i < m; i++){
        if(M[0][i] == 'S' && M[0][i] == M[n-1][i]) return true;
    }
    return false;
}
void bfs(int x,int y){
    queue<node> q;
    q.push(node(x,y));
    while(q.size()){
        node t = q.front(); q.pop();
        x = t.x, y = t.y;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(judge(nx,ny) && M[nx][ny] == '.'){
                M[nx][ny] = 'S';
                q.push(node(nx,ny));
            }else{
                if(nx >= 0 && nx < n && ny == m && M[nx][0] == '.'){
                    M[nx][0] = 'S';
                    q.push(node(nx,0));
                }
                if(nx >= 0 && nx < n && ny == -1 && M[nx][m-1] == '.'){
                    M[nx][m-1] = 'S';
                    q.push(node(nx,m-1));
                }
                if(ny >= 0 && ny < m && nx == n && M[0][ny] == '.'){
                    M[0][ny] = 'S';
                    q.push(node(0,ny));
                }
                if(ny >= 0 && ny < m && nx == 0 && M[n-1][ny] == '.'){
                    M[n-1][ny] = 'S';
                    q.push(node(n-1,ny));
                }
            }
        }
    }
}
void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j] == 'S'){
                bfs(i,j);
                if(jud()) printf("Yes\n");
                else printf("No\n");
                return;
            }
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(cin >> n >> m){
        for(int i = 0; i < n; i++) cin >> M[i];
        solve();
        for(int i = 0; i < n; i++) cout << M[i] << endl;
    }
    
    return 0;
}