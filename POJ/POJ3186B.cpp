/*
 * @Date: 2020-02-01 18:46:09
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-01 19:05:53
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,dp[2010][2010],arr[2010];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >>arr[i],dp[i][i] = arr[i]*n;
    for(int len = 1; len < n; len++){
        for(int i = 0; i+len < n; i++){
            int j = i + len;
            dp[i][j] = max(dp[i+1][j]+arr[i]*(n-len),dp[i][j-1]+arr[j]*(n-len));
        }
    }
    cout << dp[0][n-1];
    return 0;
}
//dp[l][r] = max(dp[l+1][r]+i*arr[l],dp[l][r-1]+i*arr[r]);
