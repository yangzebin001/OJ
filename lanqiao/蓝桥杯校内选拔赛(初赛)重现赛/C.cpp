/*
 * @Date: 2020-03-07 13:19:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 13:26:56
 */
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int y,m,d,dd;
  cin >> y >> m >> d >> dd;
  long long day = 23*13*y + m*13 + d + dd;
  int Y,M,D;
  Y = day/(23*13);
  M = day%(23*13)/13;
  D = day%13;
  if(D == 0){
    M--;
    D = 13;
  }
  if(M == 0){
    Y--;
    M = 23;
  }
  printf("%d %d %d",Y,M,D);
  return 0;
}