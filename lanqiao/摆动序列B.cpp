/*
 * @Date: 2020-04-16 22:11:26
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-16 22:49:17
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sum,n;
int dp[21][21]; //以x结尾，选择y个数的方案数

int main(){
  memset(dp,0,sizeof(dp));
  cin >> n;
  for(int i = 2; i <= n; i++){
    dp[i][i] = 2; 
    dp[i][2] = i*(i-1); // cn2 *2 //任意两个数+翻转一次
    for(int j = 3; j < i; j++){
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
  }
  for(int i = 2; i <= n; i++){
    sum += dp[n][i];
  }
  cout << sum;
  return 0;
}