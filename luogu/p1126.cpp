/*
 * @Date: 2020-01-21 21:15:43
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 21:05:31
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int M[55][55];
int vis[55][55][4];
int M1[55][55];
int n,m;
int sx,sy,ex,ey,dir;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int dirtonum(char c){
    if(c == 'N') return 0;
    if(c == 'E') return 1;
    if(c == 'S') return 2;
    if(c == 'W') return 3;
}
bool isvaild(int x,int y){
    if(x >= 0 && x <= n && y >= 0 && y <= m && !M[x][y]) return true;
    return false;
}
bool isvaild1(int x, int y, int dir,int step){
    if(!isvaild(x,y)) return false;
    for(int i = 1; i <= step; i++){
        // cout << x+dx[dir]*i << "&" << y+dy[dir]*i << endl;
        if(!isvaild(x+dx[dir]*i,y+dy[dir]*i)) return false;
    }
    return true;
}
struct node{
    int x,y,dir,step;
    node(){};
    node(int _x,int _y,int _dir,int _step):x(_x),y(_y),dir(_dir),step(_step){};
};

void bfs(){
    queue<node> q;
    q.push(node(--sx,--sy,dir,0));
    while(q.size()){
        node now = q.front();
        q.pop();
        if(vis[now.x][now.y][now.dir]) continue;
        // cout << now.x << " " << now.y << " " << now.dir << " " << now.step << endl;
        vis[now.x][now.y][now.dir] = 1;
        if(M1[now.x][now.y]==0)  M1[now.x][now.y]= now.step;
        if(now.x == ex && now.y == ey){
            printf("%d\n",now.step);
            return;
        }
        for(int i = 1; i <= 3; i++){
            if(isvaild1(now.x,now.y,now.dir,i)){
                q.push(node(now.x+dx[now.dir]*i,now.y+dy[now.dir]*i,now.dir,now.step+1));
//                cout << now.x+dx[dir]*i << "&" << now.y+dy[dir]*i << endl;
            }else{
                break;
            }
        }
        
        q.push(node(now.x,now.y,(now.dir+1)%4,now.step+1));
        q.push(node(now.x,now.y,(now.dir+2)%4,now.step+2));
        q.push(node(now.x,now.y,(now.dir+3)%4,now.step+1));
    }
    printf("-1\n");
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&M[i][j]);
            if(M[i][j]){
                if(i-1 >= 0) M[i-1][j] = 1;
                if(j-1 >= 0) M[i][j-1] = 1;
                if(i-1 >= 0 && j-1 >= 0) M[i-1][j-1] = 1;
            }
        }
    }
    // for(int i = 0; i < n ;i++){
    //     for(int j = 0; j < m; j++){
    //         printf("%d ",M[i][j]);
    //     }
    //     printf("\n");
    // }
    char s[3];
    scanf("%d%d%d%d%s",&sx,&sy,&ex,&ey,s);
    dir = dirtonum(s[0]);
    n -= 2; m-= 2;
    ex--;ey--;
    bfs();
    // for(int i = 0; i <= n ;i++){
    //     for(int j = 0; j <= m; j++){
    //         printf("%d ",M1[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}