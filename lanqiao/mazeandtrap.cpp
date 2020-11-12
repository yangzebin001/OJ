#include<bits/stdc++.h>

using namespace std;
int n,k;
const int MAXN = 1010;
string field[MAXN];
int vis[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
struct node{
    int x,y,kstep,tstep;
    node(int _x, int _y, int _k, int _t){
        x = _x;
        y = _y;
        kstep = _k;
        tstep = _t;
    }
    node(){}
};

int bfs(){
    if(field[0][0] == '#' || field[0][0] == 'X') return -1;
    queue<node> q;
    q.push(node(0,0,0,0));
    vis[0][0] = 1;
    node t;
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t.x == n-1 && t.y == n-1){
            return t.tstep;
        }
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + t.x;
            int ny = dy[i] + t.y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n  || field[nx][ny] == '#') continue;
            if(t.kstep == 0 && (vis[nx][ny] >= 1 || field[nx][ny] == 'X')) continue; //如果现在没有能量，并且当前格子在之前已经被访问过或者不能走。
            vis[nx][ny]++;
            if(field[nx][ny] == '%' && vis[nx][ny] == 1){
                field[nx][ny] = '#';
                vis[nx][ny] += 1;
                q.push(node(nx,ny,k,t.tstep+1));
                continue;
            }
            q.push(node(nx,ny,max(0,t.kstep-1),t.tstep+1));
        }
    }
    return -1;
}

int main(){
    while(cin >> n >> k){
        memset(vis,0,sizeof(vis));

        for(int i = 0; i < n; i++){
            cin >> field[i];
        }
        
        cout << bfs() << endl;
    }
    return 0;
}