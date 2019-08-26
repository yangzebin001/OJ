#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 50;
char m[MAXN][MAXN];

int N,M;
int sx,sy,ex,ey;
int ans;
int flag;
struct node{
    int x,y,d;
    node(){}
    node(int _x,int _y, int _d):x(_x),y(_y),d(_d){}
};

//从左顺时针
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};


void dfs(int x, int y, int pos,int t,int s){
    // printf("%d %d %d\n",x,y,d);
    if(flag) return;
    if(x == ex && y == ey){
        flag = 1;
        ans = max(ans,s);
        return;
    }
    //t = -1 表示顺时针，t = 1 表示逆时针
    //pp : 当前的方向
    //如果是左优先，就将当前方向-1开始顺时针，
    //如果是右优先，就将当前方向+1开始逆时针。
    for(int i = 1,pp = (pos+t+4)%4; i <= 4; i++,pp = (pp-t+4)%4){
        int nx = dx[pp] + x;
        int ny = dy[pp] + y;
        if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '.'){
            dfs(nx,ny,pp,t,s+1);
            if(flag) return;
        }
    }

}


void bfs(int x,int y){
    queue<node> q;
    q.push(node(x,y,1));
    m[x][y] = '#';
    node temp;
    while(q.size()){
        temp = q.front();q.pop();
        if(temp.x == ex && temp.y == ey){
            ans = temp.d;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + temp.x;
            int ny = dy[i] + temp.y;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '.'){
                m[nx][ny] = '#';
                q.push(node(nx,ny,temp.d+1));
            }
        }
    }
}

int main(){
    int T;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        int pos = 0;
        scanf("%d%d",&M,&N);
        // memset(m,0,sizeof(m));
        for(int i = 0; i < N; i++){
            scanf("%s",m[i]);
            for(int j = 0; j < M; j++){
                if(m[i][j] == 'S'){
                    sx = i,sy = j; m[i][j] = '.';
                }else if(m[i][j] == 'E'){
                    ex = i,ey = j; m[i][j] = '.';
                }
            }
        }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         printf("%c",m[i][j]);
        //     }
        //     printf("\n");
        // }
        /*
        pos = 0 表示向上为初始方向
        pos = 1 表示向右为初始方向
        pos = 2 表示向下为初始方向
        pos = 3 表示向左为初始方向
        */
        if(sx == 0) pos = 2;
        if(sx == N-1) pos = 0;
        if(sy == 0) pos = 1;
        if(sy == M-1) pos = 3;
        ans = 0;
        flag = 0;
        dfs(sx,sy,pos,-1,1);
        printf("%d",ans);
        ans = 0;
        flag = 0;
        dfs(sx,sy,pos,1,1);
        printf(" %d",ans);
        ans = 0;
        bfs(sx,sy);
        printf(" %d\n",ans);
    }
    return 0;
}