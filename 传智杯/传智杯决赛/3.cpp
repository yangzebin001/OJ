/*
 * @Date: 2020-04-11 17:39:35
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-11 20:40:49
 */
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN = 2000010;
int num[MAXN];
int main(){
  int n;
  scanf("%d",&n);
  int t = 0;
  for(int i = 0; i < n; i++){
    int a,b;
    scanf("%d%d",&a,&b);
    num[t++] = a;
    if(b != 0) num[t++] = a^b;
  }
  map<int,int> m;
  int cnt = 0;
  int cur = 0;
  for(int i = 0; i < t; i++){
    m[num[i]]++;
    if(cnt < m[num[i]]){
      cur = num[i];
      cnt = m[num[i]];
    }
    if(cnt == m[num[i]] && cur > num[i]){
      cur = num[i];
    }
  }
  printf("%d",cur);
  return 0;
}