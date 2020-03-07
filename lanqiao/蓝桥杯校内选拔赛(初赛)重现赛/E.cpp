/*
 * @Date: 2020-03-07 13:34:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 13:39:21
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL MOD = 1e9+7;
int main(){
  LL a,b;
  cin >> a >> b;
  LL ans = 0, t = a;
  while(b){
    if(b&1) ans = (ans + t)%MOD;
    t = (t+t)%MOD;
    b>>=1;
  }
  cout << ans;
  return 0;
}