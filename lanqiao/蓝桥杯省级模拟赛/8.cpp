/*
 * @Date: 2020-04-19 16:23:19
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 21:49:30
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int dp[1010][1010]; //dp[n][m] 以n结尾，长度为m的方案数
// dp[i][j] += dp[1..(i-1)][j-1]  当i是奇数
// dp[i][j] += dp[(i+1)..n][j-1]  当i是偶数
int main(){
  scanf("%d%d",&m,&n);
  for(int i = 1; i <= n; i++){
    dp[i][1] = 1;
  }
  for(int i = 2; i <= m; i++){
    for(int j = 1; j <= n; j++){
      for(int k = 1; k <= n; k++){
        if(i % 2 == 0 && j < k){      //偶数项，加dp[(j+1)..n][i-1]。
          dp[j][i] += dp[k][i-1];
        }else if(i %2 == 1 && k < j){ //奇数项，加dp[1..(j-1)][i-1]。
          dp[j][i] += dp[k][i-1]; 
        }
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    ans += dp[i][m];
  }
  printf("%lld",ans%10000);
  return 0;
}