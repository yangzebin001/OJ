/*
 * @Date: 2020-02-29 14:27:39
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-29 14:44:36
 */
#include<iostream>
#include<algorithm>
using namespace std;

const double pi = 3.14159265358979;
int main(){
  double syuan = 4*pi;
  double szheng = 9;
  double x,a,b;
  double l = 0, r = syuan;
  for(int i = 0; i < 100; i++){
    double mid = (l+r)/2;
    if(mid)
    a = (szheng-mid)/4;
    b = (syuan-szheng)/4+a;
  }
  4(syuan-szheng)+8*a = szheng+syuan-2*mid;
  return 0;
}