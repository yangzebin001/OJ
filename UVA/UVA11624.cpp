#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

const int MAXN = 1500;

struct node{
    int x,y,t,s;
    node(){}
    node(int _x,int _y,int _t,int _s):x(_x),y(_y),t(_t),s(_s){}
};

char m[MAXN][MAXN];

int N,M;

int Jx,Jy;
int Fx[MAXN];
int Fy[MAXN];
int sum;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void bfs(int x1,int y1){
    queue<node> q;
    for(int i = 0; i < sum; i++){
        q.push(node(Fx[i],Fy[i],2,0));
    }
    q.push(node(x1,y1,1,0));
    node temp;
    while(q.size()){
        temp = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + temp.x;
            int ny = dy[i] + temp.y;
            if(temp.t == 1){
                if(nx >= N || ny >= M || nx < 0 || ny < 0){
                    printf("%d\n",temp.s+1);
                    return;
                }else if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '.'){
                    m[nx][ny] = 'J';
                    q.push(node(nx,ny,1,temp.s+1));
                }
            }else if(temp.t == 2){
                if(nx >= 0 && nx < N && ny >= 0 &&ny < M && (m[nx][ny] == 'J' || m[nx][ny] == '.')){
                    m[nx][ny] = 'F';
                    q.push(node(nx,ny,2,temp.s+1));
                }
            }

        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int k = 0; k < T; k++){
        memset(m,0,sizeof(m));
        sum = 0;
        Jx = -1,Jy = -1;
        scanf("%d%d",&N,&M);
        for(int i = 0; i < N; i++){
            scanf("%s",&m[i]);
            for(int j = 0; j < M; j++){
                if(m[i][j] == 'J'){
                    Jx = i, Jy = j;
                }else if(m[i][j] == 'F'){
                    Fx[sum] = i, Fy[sum++] = j;
                }
            }
        }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         printf("%c",m[i][j]);
        //     }
        //     printf("\n");
        // }

        bfs(Jx,Jy);
        
    }
    return 0;
}