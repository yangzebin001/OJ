/*
 * @Date: 2020-01-27 14:02:29
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-27 14:15:36
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int h,x,y;
}Node[10110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int dp[110][110],M[110][110];
int n,m,cnt,ans;
int cmp(node a, node b){
    return a.h < b.h;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            Node[cnt].h = M[i][j];
            Node[cnt].x = i;
            Node[cnt++].y = j;
        }
    }
    sort(Node,Node+cnt,cmp);
    for(int i = 0; i < cnt; i++){
        int x = Node[i].x, y = Node[i].y;
        for(int j = 0; j < 4; j++){
            int nx = dx[j] + x;
            int ny = dy[j] + y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && M[nx][ny] > M[x][y]){
                dp[nx][ny] = max(dp[nx][ny],dp[x][y]+1);
                ans = max(ans,dp[nx][ny]);
            }
        }
    }
    printf("%d\n",ans+1);
    return 0;
}