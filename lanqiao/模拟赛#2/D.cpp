/*
 * @Date: 2020-02-22 13:55:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 14:07:40
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool check(int a,int b){
  int cnta1 = 0,cnta2 = 0, cntb1 = 0, cntb2 = 0;
  while(a){
    if(a%3 == 1) cnta1++;
    if(a%3 == 2) cnta2++;
    a/=3;
  }
  while(b){
    if(b%3 == 1) cntb1++;
    if(b%3 == 2) cntb2++;
    b/=3;
  }
  return abs(cnta1-cnta2) == abs(cntb1-cntb2);
}
int main(){
  // int cnt = 0;
  // for(int i = 1; i <= 2020; i++){
  //   for(int j = i; j <= 2020; j++){
  //     if(check(i,j)) {
  //       // printf("%d %d\n",i,j);  
  //       cnt++;
  //     }
  //   }
  // }
  // cout << cnt;
  cout << 472701 << endl;
  return 0;
}