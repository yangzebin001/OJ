/*
 * @Date: 2020-03-12 16:23:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-12 16:28:16
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 1e5+10;

int dp[maxn];
int arr[maxn];
int main(){
  int n;
  cin >> n;
  arr[0] = 0x3f3f3f3f;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  for(int i = 2; i <= n; i++){
    dp[i] = min(abs(arr[i-1]-arr[i])+dp[i-1],abs(arr[i-2]-arr[i])+dp[i-2]);
  }
  cout << dp[n];
  return 0;
}