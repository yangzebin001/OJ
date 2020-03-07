/*
 * @Date: 2020-02-22 16:01:43
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 16:18:05
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long dp[90];
int main(){
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= 60; i++){
    dp[i] = dp[i-1]*2;
  }
  int n;
  cin >> n;
  cout << dp[n];
  return 0;
}