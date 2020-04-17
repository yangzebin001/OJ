/*
 * @Date: 2020-04-17 21:33:21
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-17 21:47:33
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int q[5000000];
int find_k(int q[], int l, int r, int k){
  if(l >= r) return q[l];
  int i = l-1, j = r+1, x = q[l+((r-l)>>1)];
  while(i < j){
    do i++; while(q[i] < x);
    do j--; while(q[j] > x);
    if(i < j) swap(q[i],q[j]);
  }
  if(k <= j-l+1){
    return find_k(q,l,j,k);
  }else{
    return find_k(q,j+1,r,k-(j-l+1));
  }
}
int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i = 0; i < n; i++){
    scanf("%d",&q[i]);
  }
  printf("%d",find_k(q,0,n-1,k+1));
  return 0;
}