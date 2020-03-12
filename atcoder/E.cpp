/*
 * @Date: 2020-03-12 17:08:11
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-12 17:26:36
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int dp[100100];
int main(){
  cin >> n >> m;
  memset(dp,0x3f3f3f3f,sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    int v,w;
    cin >> w >> v;
    for(int j = 100000; j >= 0; j--){
      if(j >= v)
        dp[j] = min(dp[j],dp[j-v]+w);
    }
  }
  int ans = 0;
  for(int i = 100000; i >= 0; i--){
    if(dp[i] <= m){
      ans = i;
      break;
    }
  }
  cout << ans;
  // cout << dp[n][90];
  return 0;
}