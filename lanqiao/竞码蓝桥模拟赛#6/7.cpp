/*
 * @Date: 2020-05-09 14:23:40
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 14:35:25
 */
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int M[1000][1000];
int k,r;
int rx,ry;

bool dis(double x, double y, double d1, double d2){
  double dd = sqrt((x-rx)*(x-rx) + (y-ry)*(y-ry));
  return dd >= d1 && dd <= d2;
}

int main(){
  scanf("%d%d",&k,&r);
  rx = k*r+1,ry = k*r+1;
  //左上
  for(int i = rx; i >= 1; i--){
    for(int j = ry; j >= 1; j--){
      for(int kk = 0; kk < k; kk++){
        if(dis(i,j,kk*r+1,(kk+1)*r)){
          M[i][j] = kk+1;
          break;
        }
      }
    }
  }
  for(int i = 1; i <= 2*r+1; i++){
    for(int j = 1; j <= 2*r+1; j++){
      if(M[i][j] == 0) printf("  ");
      else printf("%2d",M[i][j]);
    }
    printf("\n");
  }
  return 0;
}