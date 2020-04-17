/*
 * @Date: 2020-04-17 21:49:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-17 21:56:18
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{
  int x,y,z;
  node(){};
  node(int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _y;
  }
}Node[50000];

int cmp(node &a, node &b){
  return a.z < b.z;
}

double compute(node &a, node &b){
  return sqrt(1.0* (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d%d%d",&Node[i].x,&Node[i].y,&Node[i].z);
  }
  sort(Node,Node+n,cmp);
  double ans = 0.0;
  for(int i = 1; i < n; i++){
    ans += compute(Node[i],Node[i-1]);
  }
  printf("%.3f",ans);
  return 0;
}