/*
 * @Date: 2020-01-30 17:51:27
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-30 17:58:31
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
const int MAXN = 210;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN];
int n,m;

int main(){
    int ans = 0;
    memset(dp,-INF,sizeof dp);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> dp[i][j];
        }
    }
    dp[n+1][(m+1)/2] = 0;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            dp[i][j] += max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
            ans = max(ans,dp[i][j]);
        }
    }
    cout <<ans;
    return 0;
}