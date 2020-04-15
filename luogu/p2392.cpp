/*
 * @Date: 2020-03-13 21:24:13
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-13 21:43:58
 */
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int cnt[4];
int arr[30];
int ans,minn,l,r;

void dfs(int i, int n){
  if(i == n){
    minn = min(minn,max(l,r));
    return;
  }
  l += arr[i];
  dfs(i+1,n);
  l -= arr[i];
  r += arr[i];
  dfs(i+1,n);
  r -= arr[i];
}

int main(){
  for(int i = 0; i < 4; i++) cin >> cnt[i];
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < cnt[i]; j++){
      cin >> arr[j];
    }
    l = r = 0;
    minn = INT_MAX;
    dfs(0,cnt[i]);
    ans += minn;
  }
  cout << ans;
  
  return 0;
}