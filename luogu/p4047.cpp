/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 14:33:37 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 15:24:54
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN = 1010;
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

int n,m;
int main(){
    //我们把每个点看成一个部落，每次取最小距离的两个抱团，
    //同时部落也减少了一个....然后减减减，直到部落数==目标数，
    //此时下一个不同部落的距离就是最短的距离！
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < MAXN; i++) F[i] = i;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
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
            if(cnt == n-m+1){
                printf("%.2f\n",w);
            }
        }
    }
    return 0;
}