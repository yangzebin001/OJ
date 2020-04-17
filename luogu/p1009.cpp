/*
 * @Date: 2020-04-17 21:22:07
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-17 21:32:10
 */
#include<iostream>
#include<cstdio>
using namespace std;
int ans[1000], mid[1000];

void add(int *a, int *b){
  int jw = 0;
  for(int i = 0; i < 1000; i++){
    a[i] += b[i]+jw;
    jw = a[i]/10;
    a[i] %= 10;
  }
}

void mul(int *a, int b){
  int jw = 0;
  for(int i = 0; i < 1000; i++){
    a[i] = a[i] * b +jw;
    jw = a[i]/10;
    a[i] %= 10;
  }
}
int main(){
  int n;
  cin >> n;
  mid[0] = 1;
  for(int i = 1; i<= n; i++){
    mul(mid,i);
    add(ans,mid);
  }
  int f = 0;
  for(int i = 1000-1; i >= 0; i--){
    if(ans[i]) f = 1;
    if(f) printf("%d",ans[i]);
  }
  return 0;
}