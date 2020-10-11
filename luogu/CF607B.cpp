/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 15:40:50 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 15:55:39
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 550;
int dp[MAXN][MAXN];
int a[MAXN];
int main(){
    int n;
    cin >> n;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i][i] = 1;
    for(int i = 1; i < n; i++){
        dp[i][i+1] = 1 + (a[i] != a[i+1]);  //因为是回文串，所以长度为2的特殊处理一下
    }
    for(int len = 3; len <= n; len++){
        for(int i = 1; i+len-1 <= n; i++){
            int j = i+len-1;
            if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1];
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}