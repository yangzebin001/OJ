/*
 * @Date: 2020-02-11 18:01:49
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 18:10:25
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[50][50]; //i,j 表示第i轮，第j个人
int main(){
    int n,k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] += dp[i-1][(n+j-1)%n];
            dp[i][j] += dp[i-1][(j+1)%n];
        }
    }
    cout << dp[k][0];
    return 0;
}