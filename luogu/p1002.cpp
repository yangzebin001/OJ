/*
 * @Date: 2020-04-17 21:58:57
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-17 22:15:44
 */
#include<iostream>
#include<cstdio>
using namespace std;
long long M[22][22];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int main(){
  int n,m;
  int x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for(int i = 0; i < 8; i++){
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if(nx >= 0 && nx <= n && ny >= 0 && ny <= m){
      M[nx][ny] = -1;
    }
  }
  M[0][0] = 1;
  M[x][y] = -1;
  for(int i = 1; i <= n; i++){
    if(M[i][0] == -1) continue;
    if(M[i-1][0] != -1) M[i][0] += M[i-1][0];
  }
  for(int j = 1; j <= m; j++){
    if(M[0][j] == -1) continue;
    if(M[0][j-1] != -1) M[0][j] += M[0][j-1];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(M[i][j] == -1) continue;
      if(M[i-1][j] != -1) M[i][j] += M[i-1][j];
      if(M[i][j-1] != -1) M[i][j] += M[i][j-1];
    }
  }
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= m; j++){
  //     printf("%d ",M[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%lld",M[n][m]);
  return 0;
}