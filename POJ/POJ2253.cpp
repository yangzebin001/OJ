#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<queue>
#include<vector>
#define MK make_pair
using namespace std;

const int MAXN = 250;
const double INF = 1<<30;
double M[MAXN][MAXN];
double dis[MAXN];
int vis[MAXN];
int N;

double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

struct node{
    double x,y;
    node(){}
    node(double _x,double _y):x(_x),y(_y){}
}Edge[MAXN];

typedef pair<double,int> P;

void Dijkstra(int S){
    for(int i = 0; i < N; i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[S] = 0;
    priority_queue<P,vector<P>,greater<P> > pq;
    pq.push(MK(0,S));
    while(!pq.empty()){
        P t = pq.top();pq.pop();
        if(vis[t.second]) continue;
        vis[t.second] = 1;
        for(int i = 0; i < N; i++){
            if(max(dis[t.second],M[t.second][i]) < dis[i]){
                dis[i] = max(dis[t.second],M[t.second][i]);
                pq.push(MK(dis[i],i));
            }
        }
    }
}


//题意，在所有最长路径中，求一个最短的。
// 所以松弛操作为：if(d[i] > max(d[j],d[k])) d[i] = max(d[j],d[k]);

int main(){
    freopen("in.txt","r",stdin);
    int cc = 0;
    while(~scanf("%d",&N) && N){
        fill_n(M[0],MAXN*MAXN,INF);
        for(int i = 0; i < N; i++){
            int a,b;
            scanf("%d%d",&a,&b);
            Edge[i].x =a; Edge[i].y = b;
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                M[i][j] = M[j][i] = distance(Edge[i].x*1.0,Edge[i].y*1.0,Edge[j].x*1.0,Edge[j].y*1.0);
                
            }
        }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         printf("%.3lf ",M[i][j]);
        //     }
        //     printf("\n");
        // }
        Dijkstra(0);
        if(cc != 0) printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3f\n",++cc,dis[1]);
    }
    return 0;
}