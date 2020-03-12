/*
 * @Date: 2020-03-12 16:40:50
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-12 16:45:35
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int dp[2][3];
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a,b,c;
    cin >> a >> b >> c;
    dp[1][0] = max(dp[0][1],dp[0][2]) + a;
    dp[1][1] = max(dp[0][0],dp[0][2]) + b;
    dp[1][2] = max(dp[0][0],dp[0][1]) + c;
    dp[0][0] = dp[1][0];
    dp[0][1] = dp[1][1];
    dp[0][2] = dp[1][2];
  }
  cout << max(dp[0][0],max(dp[0][1],dp[0][2]));
  return 0;
}