/*
 * @Date: 2020-02-22 15:12:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 17:06:19
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD = 998244353;
int n,m,dp[11000][11000],arr[11000];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= arr[i] && j-k>=0; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i <= m; i++) sum = (sum + dp[n][i])%MOD;
    cout << sum;
    return 0;
}