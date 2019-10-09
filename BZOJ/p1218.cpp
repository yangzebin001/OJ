/*
 * @Date: 2019-09-19 21:00:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-19 21:00:10
 */
#include<iostream>
#include<cstdio>
using namespace std;
int map[5010][5010],ans,l,r,i,j,x,y,v,N,R;
int main(){
    scanf("%d%d",&N,&R);
    r = l = R;
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d",&x,&y,&v);
        map[++x][++y] = v;
        l = max(l,x);
        r = max(r,y);
    }
    
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= r; j++){
            map[i][j] =  map[i-1][j] + map[i][j-1] - map[i-1][j-1] +map[i][j];
        }
    }
    for(int i = R; i <= l; i++){
        for(int j = R; j <= r; j++){
            ans = max(ans, map[i][j] - map[i-R][j] - map[i][j-R] + map[i-R][j-R]);
        }
    }
    printf("%d",ans);
    return 0;
}
