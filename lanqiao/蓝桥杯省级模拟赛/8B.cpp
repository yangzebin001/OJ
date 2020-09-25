/*
 * @Date: 2020-04-19 16:23:19
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 10:40:14
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
long long dp[1010][1010]; //dp[n][m] 以n结尾，长度为m的方案数
int main(){
  scanf("%d%d",&m,&n);
  for(int i = 1; i <= n; i++){
    dp[i][1] = 1;  //base,以i结尾长度为1
  }
  for(int i = 2; i <= m; i++){
    long long sum = 0;
    if(i %2 == 1){ //奇数项，加dp[1..(j-1)][i-1]。
      for(int j = 1; j <= n; j++){
        dp[j][i] = (sum + dp[j][i])%10000;
        sum = (sum + dp[j][i-1])%10000;
      }
    }
    sum = 0;
    if(i %2 == 0){ //偶数项，加dp[(j+1)..n][i-1]。
      for(int j = n; j >= 1; j--){
        dp[j][i] = (sum + dp[j][i])%10000;
        sum = (sum + dp[j][i-1])%10000;
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    ans = (ans + dp[i][m])%10000;
  }
  printf("%lld",ans);
  return 0;
}