/*
 * @Date: 2020-03-14 15:28:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-25 20:34:15
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[1010][1010];

long long dfs(int x, int y){
  if(y <= 0) return 0;
  if(dp[x][y]) return dp[x][y];
  return dp[x][y] = (dfs(x,y-1) + dfs(y,abs(x-y)-1) + 1)%10000;
}

int main(){

  long long cnt = 0,sum = 0;
  int n;
  scanf("%d",&n);
  sum = dfs(n,n);
  printf("%d",sum);
  return 0;
}