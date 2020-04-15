/*
 * @Date: 2020-04-11 18:15:40
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-11 20:30:09
 */
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
const int MAXN = 1000010;
int n;
int l[MAXN],r[MAXN];
int num[MAXN];
map<int,int> m;
int main(){
  scanf("%d",&n);
  int minnum = INT_MAX;
  num[0] = num[n+1] = INT_MAX;
  for(int i = 1; i <= n; i++){
    scanf("%d",&num[i]);
    l[i] = r[i] = 1;
  }
  for(int i = 2; i <= n; i++){
    if(num[i] > num[i-1]){
      l[i] = l[i-1]+1;
    }
    if(num[i] == num[i-1]){
      l[i] = l[i-1];
    }
  }
  for(int i = n-1; i >= 1; i--){
    if(num[i] > num[i+1]){
      r[i] = r[i+1]+1;
    }
    if(num[i] == num[i+1]){
      r[i] = r[i+1];
    }
  }
  long long sum = 0;
  for(int i = 1; i <= n; i++){
    int d = max(l[i],r[i]);
    sum += d;
    // printf("%d ", d);
  }
  printf("%ld",sum);
  return 0;
}