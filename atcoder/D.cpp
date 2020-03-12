/*
 * @Date: 2020-03-12 16:47:56
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-12 16:54:26
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m;
LL dp[100010];
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    LL v,w;
    cin >> w >> v;
    for(int j = m; j >= w; j--){
      dp[j] = max(dp[j],dp[j-w]+v);
    }
  }
  cout << dp[m];
  // cout << *max_element(dp,dp+m);
  return 0;
}