/*
 * @Date: 2020-01-15 19:09:50
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-15 19:45:11
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 1010;
int M[MAXN][MAXN];
int M1[MAXN][MAXN];
int vis[MAXN][MAXN];
int step[MAXN*MAXN][2];
int n,m;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int bfs(int i, int j){
    if(M1[i][j]) return M1[i][j];
    int cnt = 0;
    queue<pair<int,int> > q;
    q.push({i,j});
    vis[i][j] = 1;
    while(q.size()){
        pair<int,int> t = q.front();
        step[cnt][0] = t.first;
        step[cnt][1] = t.second;
        q.pop();
        cnt++;
        for(int k = 0; k < 4; k++){
            int nx = t.first+dx[k];
            int ny = t.second+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(M[nx][ny] == 1-M[t.first][t.second] && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    for(int i = 0; i < cnt; i++){
        M1[step[i][0]][step[i][1]] = cnt;
    }
    return cnt;
    
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m) >> n >> m;
    for(int i = 0; i < n; i++){
        char a[MAXN];
        scanf("%s",a);
        for(int j = 0; j < strlen(a); j++){
            if(a[j] == '1') M[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",bfs(--a,--b));
    }
    return 0;
}