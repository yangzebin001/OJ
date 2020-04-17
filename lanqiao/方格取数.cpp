/*
 * @Date: 2020-04-16 22:55:01
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-16 23:32:39
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int N[20][20];
int dp[20][20][20][20];
int main(){
  int n;
  cin >> n;
  memset(dp,0,sizeof(dp));
  memset(N,0,sizeof(N));
  for(; ; ){
    int a,b,c;
    if(a + b+c == 0)break;
    cin >> a >> b >> c;
    N[a][b] = c; 
  }
  
  for(int ax = 1; ax <= n; ax++){
  for(int ay = 1; ay <= n; ay++){
  for(int bx = 1; bx <= n; bx++){
  for(int by = 1; by <= n; by++){
    if(ax+ay != bx+by) continue;
    int temp = 0;
    temp = max(dp[ax-1][ay][bx-1][by],dp[ax-1][ay][bx][by-1]);
    temp = max(temp,dp[ax][ay-1][bx-1][by]);
    temp = max(temp,dp[ax][ay-1][bx][by-1]);
    if(ax == bx && ay == by) dp[ax][ay][bx][by] = N[ax][ay] + temp;
    else dp[ax][ay][bx][by] = N[ax][ay] + N[bx][by] + temp;
  }
  }
  }
  }
  cout << dp[n][n][n][n] << endl;
  return 0;
}