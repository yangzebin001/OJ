#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int field[310][310];
int vis[310][310];
struct point{
    int x, y, s;
    point(int _x, int _y, int _s){
        x = _x;
        y = _y;
        s = _s;
    }
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<point> q;
int m;
int main(){
    memset(field, 0x3f3f3f3f, sizeof(field));
    cin >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        field[a][b] = min(field[a][b], c);
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if(nx >= 0 && ny >= 0){
                field[nx][ny] = min(field[nx][ny], c);
            }
        }
    }
    struct point start(0,0,0);
    vis[0][0] = 1;
    q.push(start);
    while(q.size()){
        struct point a = q.front(); q.pop();
        
        
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + a.x;
            int ny = dy[i] + a.y;
            if(nx >= 0  && ny >= 0  && !vis[nx][ny] && a.s + 1 < field[nx][ny]){
                q.push(point(nx, ny, a.s+1));
                vis[nx][ny] = 1;
                if(field[nx][ny] == 0x3f3f3f3f){
                    cout << a.s+1 << endl;
                    return 0;
                }
            }
        }
    }
    printf("%d", -1);
    return 0;
}