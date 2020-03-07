/*
 * @Date: 2020-02-22 16:29:12
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 16:41:18
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1e5+10;
struct node{
  int a,b;
}Node[MAXN];
int cmp(node x, node y){
  return x.b > y.b;
}
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  int maxa = 0;
  for(int i = 0; i < n; i++){
    scanf("%d%d",&Node[i].a,&Node[i].b);
    maxa = max(maxa,Node[i].a);
  }
  sort(Node,Node+n,cmp);
  int i = 0,cnt = 0;
  while(1){
    if(i >= n) break;
    if(Node[i].b < maxa){
      break;
    }
    m -= Node[i].b;
    cnt++;
    i++;
    if(m <= 0) break;
  }
  if(m <= 0){
    printf("%d\n",cnt);
    return 0;
  }
  while(m > 0){
    m -= maxa;
    cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}