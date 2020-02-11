/*
 * @Date: 2020-02-09 14:35:17
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-09 15:01:20
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
int dp[2020][2020];
// dp[i][j] = 前i个数，最大数为B[j]时的最小代价
// dp[i][j] = min{dp[i-1][k](0-j)} + abs(a[i],B[j])
int arr[2020],brr[2020];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i], brr[i] = arr[i];
    sort(brr+1,brr+1+n);
    for(int i = 1; i <= n; i++){
        int minval = INT_MAX;
        for(int j = 1; j <= n; j++){
            minval = min(minval,dp[i-1][j]);
            dp[i][j] = abs(arr[i]-brr[j]) + minval;
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) ans = min(ans,dp[n][i]);
    cout << ans;
    return 0;
}