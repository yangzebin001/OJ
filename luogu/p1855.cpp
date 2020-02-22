/*
 * @Date: 2020-02-13 19:28:21
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-13 19:33:32
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[110][2], dp[110][210][210]; //前i个人，在j金钱下k时间下实现愿望的个数
int main(){
    int n,m,t;
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= t; k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j-arr[i][0] >= 0 && k-arr[i][1] >= 0){
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-arr[i][0]][k-arr[i][1]]+1);
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= m; j++){
        for(int k = 0; k <= t; k++){
            ans = max(ans,dp[n][j][k]);
        }
    }
    cout << ans;
    return 0;
}