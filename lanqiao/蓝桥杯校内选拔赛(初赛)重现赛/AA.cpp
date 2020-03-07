/*
 * @Date: 2020-03-07 16:56:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 17:43:20
 */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
bool check(int x){
  for(int i = 2; i *i <= x; i++){
    if(x%i == 0) return false;
  }
  return true;
}
int vis[5000];
int main(){
  int i;
  for(i = 2; i < 5000; i++){
    if(check(i)) vis[i] = 1;
  }
  for(int i = 2; i < 5000; i++){
    if(vis[i]) cnt++;
    
    if(cnt == 300) cout << i <<endl;
  }
  // cout << 1987 << endl;
  return 0;
}