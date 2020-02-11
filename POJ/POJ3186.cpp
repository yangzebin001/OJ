/*
 * @Date: 2020-02-01 18:46:09
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-01 19:00:16
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,dp[2010][2010],arr[2010];
int dfs(int i,int l, int r){
    if(l == r) return i*arr[l];
    if(dp[l][r] != 0) return dp[l][r];
    return dp[l][r] = max(dfs(i+1,l+1,r) + i*arr[l], dfs(i+1,l,r-1)+i*arr[r]);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >>arr[i];
    cout << dfs(1,0,n-1);
    return 0;
}
//dp[l][r] = max(dp[l+1][r]+i*arr[l],dp[l][r-1]+i*arr[r]);
