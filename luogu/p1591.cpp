/*
 * @Date: 2020-04-15 21:39:46
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-15 22:33:19
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int n,a;

void mul(string &a, int b){
  string c;
  for(int i = 0, t = 0; i < a.size() || t; i++){
    if(i < a.size()) t += (a[i]-'0')*b;
    c += '0' + (t%10);
    t /= 10;
  }
  a = c;
}
int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d%d",&n,&a);
    string res = "1";
    int cnt = 0;
    for(int i = 2; i <= n; i++){
      mul(res,i);
    }
    for(int i = 0; i < res.size(); i++){
      if(res[i]-'0' == a) cnt++;
    }
    printf("%d\n",cnt);
  }
  return 0;
}