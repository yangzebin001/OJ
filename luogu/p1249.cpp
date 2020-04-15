/*
 * @Date: 2020-04-14 20:50:40
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-14 21:44:31
 */
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int res[10000],cnt = 0;

void mul(string &ans, int a){
  string c;
  for(int i = 0, t = 0; i < ans.size() || t; i++){
    if(i < ans.size()) t += ((ans[i]-'0')*a);
    c += ('0' + (t %10));
    t /= 10;
  }
  ans = c;
}
int main(){
  int n;
  cin >> n;
  int num = 3, sum;
  res[++cnt] = sum = 2;
  while(sum < n){
    sum += num;
    res[++cnt] = num;
    num++;

  }
  int r = sum-n;
  if(r == 1){
    res[cnt] += 1;
    r = 2;
  }
  string ans = "1";
  for(int i = 1; i <= cnt; i++){
    if(res[i] != r){
      printf("%d ",res[i]);
      mul(ans,res[i]);
    }
  }
  reverse(ans.begin(),ans.end());
  cout << endl << ans;
  return 0;
}