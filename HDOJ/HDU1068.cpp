/*
 * @Date: 2020-02-01 19:35:22
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-01 21:11:55
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
const int MAXN = 110;
int a[MAXN][MAXN],dp[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool judge(int x, int y){
    return x>=0 && x < n && y >= 0 && y < n;
}
int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = a[x][y];
    int t = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= k; j++){
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;
            if(judge(nx,ny) && a[nx][ny] > a[x][y]){
                t = max(t,dfs(nx,ny));
            }
        }
    }
    dp[x][y] += t;
    return dp[x][y];
}
void solve(){
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        }
    }
    cout << dfs(0,0) << endl;
}
int main(){
    while(cin >> n >> k, n != -1 && k != -1){
        solve();
    }
    return 0;
}