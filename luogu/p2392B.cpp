/*
 * @Date: 2020-03-13 21:24:13
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-13 21:55:01
 */
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int cnt[4];
int arr[30];
int ans,minn,l,r;
int dp[30*60];


int main(){
  for(int i = 0; i < 4; i++) cin >> cnt[i];
  for(int i = 0; i < 4; i++){
    int sum = 0;
    for(int j = 0; j < cnt[i]; j++){
      cin >> arr[j];
      sum += arr[j];
    }
    memset(dp,0,sizeof(dp));
    for(int j = 0; j < cnt[i]; j++){
      for(int k = sum/2; k >= arr[j]; k--){
        dp[k] = max(dp[k],dp[k-arr[j]]+arr[j]); //在sum/2容量下，能装的最多的价值，最多不会超过sum/2
      }
    }
    ans += sum-dp[sum/2]; // 因为dp[sum/2]<= sum/2 所以取sum-dp[sum/2]
  }
  cout << ans;
  
  return 0;
}