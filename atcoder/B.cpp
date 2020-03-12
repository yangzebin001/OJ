/*
 * @Date: 2020-03-12 16:23:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-12 16:35:46
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 1e5+10;

int dp[maxn];
int arr[maxn];
int main(){
  int n,k;
  cin >> n >> k;
  arr[0] = 0x3f3f3f3f;
  memset(dp,0x3f3f3f3f,sizeof(dp));
  dp[1] = 0;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= k; j++){
      if(i-j <= 0) continue;
      dp[i] = min(dp[i],abs(arr[i-j]-arr[i])+dp[i-j]);
    }
  }
  cout << dp[n];
  return 0;
}