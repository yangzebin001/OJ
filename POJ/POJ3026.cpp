/*
 * @Date: 2019-08-27 15:44:23
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-27 16:45:07
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#include<queue>
#define MK make_pair
using namespace std;

struct node{
    int x,y,s;
    node(){}
    node(int _x,int _y,int _s):x(_x),y(_y),s(_s){}
};

int dx[5] = {-1,0,1,0};
int dy[5] = {0,1,0,-1};
const int MAXN = 110;
const int INF = 0x3f3f3f3f;

char MA[MAXN][MAXN];
int vis[MAXN][MAXN];
int G[MAXN][MAXN];


int lowc[MAXN];
int v[MAXN];

int N,M;
map<pair<int,int>, int> toP;

void bfs(int x,int y){
    queue<node> q;
    int vis1[MAXN][MAXN] = {0};
    q.push(node(x,y,0));
    vis1[x][y] = 1;
    node temp;
    while(q.size()){
        temp = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + temp.x;
            int ny = dy[i] + temp.y;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && MA[nx][ny] != '#' && vis1[nx][ny] == 0){
                q.push(node(nx,ny,temp.s+1));
                vis1[nx][ny] = 1;
                if(vis[nx][ny]) G[toP[MK(x,y)]][toP[MK(nx,ny)]] = temp.s+1;
            }
        }
    }
}

int Pirm(int N){
    memset(lowc,INF,sizeof(lowc));
    memset(v,0,sizeof(v));
    int ans = 0;
    v[0] = 1;
    for(int i = 1; i < N; i++) lowc[i] = G[0][i];
    for(int i = 1; i < N; i++){
        int Min = INF;
        int k = -1;
        for(int j = 0; j < N; j++){
            if(!v[j] && Min > lowc[j]){
                Min = lowc[j]; k = j;
            }
        }
        if(k == -1) return -1; 
        ans += Min;
        v[k] = 1;
        for(int j = 0; j < N; j++){
            if(!v[j] && lowc[j] > G[k][j]){
                lowc[j] = G[k][j];
            }
        }
    } 
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&M,&N);
        char c;
        int len = 0;
        while((c = getchar()) != '\n');
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%c",&MA[i][j]);
                if(MA[i][j] == 'S' || MA[i][j] == 'A'){
                    vis[i][j] = 1;
                    toP[MK(i,j)] = len++;
                }
            }
            getchar();
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(vis[i][j]) bfs(i,j);
            }
        }
        // for(int i = 0; i < 10; i++){
        //     for(int j = 0; j < 10; j++){
        //         printf("%d ",G[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("%d\n",Pirm(len));
        
    }
    return 0;
}