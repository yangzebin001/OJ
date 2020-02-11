/*
 * @Date: 2020-02-09 21:28:13
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-09 21:46:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int F[1010];
int getF(int x){
    return F[x] == -1 ? x : F[x] = getF(F[x]);
}
void _union(int x, int y){
    x = getF(x);
    y = getF(y);
    if(x != y){
        F[x] = y;
    }
}
bool issame(int a,int b){
    return getF(a) == getF(b);
}
struct Edge{
    int x,y,t;
    Edge(int _x, int _y, int _t):x(_x),y(_y),t(_t){};
    Edge(){};
}edge[100100];
int cmp(Edge a,Edge b){
    return a.t < b.t;
}
int n,m;
int main(){
    memset(F,-1,sizeof(F));
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].t);
    }
    sort(edge,edge+m,cmp);
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(!issame(edge[i].x,edge[i].y)){
            ans = max(edge[i].t,ans);
            _union(edge[i].x,edge[i].y);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(F[i] == -1) cnt++;
        if(cnt > 1){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans);

    return 0;
}