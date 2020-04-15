/*
 * @Date: 2020-04-01 12:36:00
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-01 12:51:29
 */
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct node{
  double m,v;
  double avg;
}Node[110];

int cmp(const node& a, const node& b){
  return a.avg > b.avg;
}
int main(){
  int n,t;
  cin >> n >> t;
  for(int i = 0; i < n; i++){
    cin >> Node[i].m >> Node[i].v;
    Node[i].avg = Node[i].v/Node[i].m;
  }
  sort(Node, Node+n, cmp);
  double ans = 0;
  for(int i = 0; i < n; i++){
    if(t >= Node[i].m){
      ans += Node[i].v;
      t -= Node[i].m;
    }else{
      ans += Node[i].avg*t;
      break;
    }
  }
  printf("%.2f",ans);
  
  return 0;
}