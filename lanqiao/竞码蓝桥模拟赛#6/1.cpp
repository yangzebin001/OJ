/*
 * @Date: 2020-05-09 13:28:53
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 13:34:35
 */
#include<iostream>
using namespace std;
int a,b,c,d,e;
bool check(){
  bool A = a+18+25 == 24+c+e && 24+c+e == b+d+21;
  bool B = a+24+b == 18+c+d && 18+c+d == 25+e+21 && a+18+25 == 25+e+21;
  bool C = a+c+21 == b+c+25 && b+c+25 == a+24+b;
  return  A && B && C;
}
int main(){
  for(a = 1; a <= 100; a++)
  for(b = 1; b <= 100; b++)
  for(c = 1; c <= 100; c++)
  for(d = 1; d <= 100; d++)
  for(e = 1; e <= 100; e++){
    if(check()){
      printf("%d %d %d %d %d\n",a,b,c,d,e);
    }
  }
  
  return 0;
}