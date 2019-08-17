#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
const int MAXN = 40;
const int INF = 0x3f3f3f3f;

char m[MAXN][MAXN][MAXN];
int v[MAXN][MAXN][MAXN];
int L,R,C;

int si,sx,sy,ei,ex,ey;
int dirz[] = {0,0,0,0,-1,1};
int dirx[] = {-1,0,1,0,0,0};
int diry[] = {0,1,0,-1,0,0};
struct node{
    int x,y,z;
    node(){}
    node(int z,int x,int y):x(x),y(y),z(z){

    }
};

void bfs(int k,int x,int y){
    queue<node> q;
    q.push(node(k,x,y));
    node temp;
    while(q.size()){
        temp = q.front();q.pop();
        int dx = temp.x,dy = temp.y,dz = temp.z;
        if(dx == ex && dy == ey && dz == ei) return;
        int val = v[dz][dx][dy];
        for(int i = 0; i < 6; i++){
            int ddx = dx+dirx[i];
            int ddy = dy+diry[i];
            int ddz = dz+dirz[i];
            if(ddz >= 0 && ddz < L && ddx >= 0 && ddx < R && ddy >= 0 && ddy < C && m[ddz][ddx][ddy] == '.' && v[ddz][ddx][ddy] == INF){
                v[ddz][ddx][ddy] = val+1;
                q.push(node(ddz,ddx,ddy));
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d",&L,&R,&C);
    while(L != 0 && R != 0 && C != 0){
        memset(m,0,sizeof(m));
        memset(v,INF,sizeof(v));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                scanf("%s",m[i][j]);
                for(int k = 0; k < C; k++){
                    if(m[i][j][k] == 'S'){
                        si = i;
                        sx = j;
                        sy = k;
                        m[i][j][k] = '.';
                    }
                    if(m[i][j][k] == 'E'){
                        ei = i;
                        ex = j;
                        ey = k;
                        m[i][j][k] = '.';
                    }
                }
            }
        }
        v[si][sx][sy] = 0;
        bfs(si,sx,sy);
        if(v[ei][ex][ey] != INF){
            printf("Escaped in %d minute(s).\n",v[ei][ex][ey]);
        }else{
            printf("Trapped!\n");
        }
        scanf("%d%d%d",&L,&R,&C);
    }
    return 0;
}
