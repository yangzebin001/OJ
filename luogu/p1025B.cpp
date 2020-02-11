/*
 * @Date: 2020-02-11 17:49:51
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 17:58:03
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[210][10];
//dp[i][j] = 将i分为j组的方案数
//dp[i][j] = dp[i-1][j-1](第j种方案为1) + dp[i-j][j]（i-j每组都加1变为i）
int main(){
    int n,k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int j = 1; j <= k; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] = dp[i-1][j-1];
            if(i >= j) dp[i][j] += dp[i-j][j];
        }
    }
    cout << dp[n][k];
    return 0;
}