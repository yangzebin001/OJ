#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>

using namespace std;

int m[10][10];
int dis[10][10];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};



void bfs1(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    dis[0][0] = 0;
    while(q.size()){
        pair<int,int> t = q.front(); q.pop();
        for(int i = 0; i <4; i++){
            int nx = dx[i] + t.first;
            int ny = dy[i] + t.second;
            if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && m[nx][ny] == 0 && dis[nx][ny] == -1){
                dis[nx][ny] = dis[t.first][t.second] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

stack<pair<int,int> > s;
pair<int,int> cur;
int curstep =-1;
void bfs2(){
    cur = make_pair(4,4);
    curstep = dis[4][4];
    s.push(cur);
    while(1){
    for(int i = 0; i < 4; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && dis[nx][ny] == curstep - 1){
            cur = pair<int,int>(nx,ny);
            curstep = dis[nx][ny];
            // printf("x = %d  y = %d  s = %d\n",nx,ny,curstep);
            s.push(cur);
            if(curstep == 0) return;
        }
    }}
}

int main(){
    freopen("in.txt","r",stdin);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&m[i][j]);
        }
    }
    memset(dis,-1,sizeof(dis));
    bfs1();
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         printf("%2d",dis[i][j]);
    //     }
    //     printf("\n");
    // }
    bfs2();
    while(s.size()){
        cur = s.top();s.pop();
        printf("(%d, %d)\n",cur.first,cur.second);
    }
}