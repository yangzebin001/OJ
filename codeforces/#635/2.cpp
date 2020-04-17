/*
 * @Date: 2020-04-15 23:04:47
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-15 23:45:06
 */
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
#include<set>
using namespace std;

struct node{
  int x, n, m;
  node(){};
  node(int _x, int _n, int _m){
    x = _x;
    n = _n;
    m = _m;
  }
};
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int x,n,m;
    scanf("%d%d%d",&x,&n,&m);
    while(n){
      int c = x/2+10;
      if(c <= x){
        x = c;
        n--;
      }else break;
    }
    x -= m*10;
    if(x <= 0){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}