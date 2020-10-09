/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 14:33:37 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-08 14:33:37 
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN = 600;
int x[MAXN],y[MAXN], xi,yi;
double getdis(int a, int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*((y[a]-y[b])));
}
struct e{
    int u,v;
    double w;
}edge[MAXN*MAXN];
int tol;

int F[MAXN];
int getf(int x){
    return F[x] == x ? x : F[x] = getf(F[x]);
}

bool cmp(e &a, e &b){
    return a.w < b.w;
}

int s,m;
int main(){
    cin >> s >> m;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < MAXN; i++) F[i] = i;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            edge[tol].u = i;
            edge[tol].v = j;
            edge[tol++].w = getdis(i,j);
        }
    }
    sort(edge, edge+tol, cmp);
    int cnt = 0;
    for(int i = 0; i < tol; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        int a = getf(u);
        int b = getf(v);
        if(a != b){
            cnt++;
            F[a] = b;
            if(cnt == m-s){
                printf("%.2f\n",w);
            }
        }
    }
    return 0;
}