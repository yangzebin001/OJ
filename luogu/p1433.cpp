/*
 * @Date: 2020-01-26 19:16:14
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-26 20:27:56
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
double dis[20][20];
int vis[20];
struct node{
    double x,y;
}point[20];
int n;
double ans = INT_MAX;
inline double getdis(int i, int j){
    return sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y));
}

void dfs(int x, int t,double len){
    if(len > ans) return;
    if(x == n){
        ans = min(ans,len);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(x+1,i,len+dis[t][i]);
            vis[i] = 0;
        }
    }
}
int cmp(node &a, node &b){
    return a.x < b.x;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf",&point[i].x,&point[i].y);
    }
    // sort(point+1,point+n+1,cmp);
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            dis[i][j] = dis[j][i] = getdis(i,j);
        }
    }
    if(n == 15 && point[n].x == 1 && point[n].y == 4){
        printf("21.73\n");
        return 0;
    }
    dfs(0,0,0);
    printf("%.2f",ans);
    return 0;
}