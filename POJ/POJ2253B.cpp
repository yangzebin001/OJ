#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN = 250;
const double INF = 1<<30;
double M[MAXN][MAXN];
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

void floyd(){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(M[i][j] > max(M[i][k],M[k][j])){
                    M[i][j] = max(M[i][k],M[k][j]);
                }
            }
}



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

        floyd();
        if(cc != 0) printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3f\n",++cc,M[0][1]);
    }
    return 0;
}