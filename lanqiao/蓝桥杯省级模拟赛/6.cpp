/*
 * @Date: 2020-04-19 14:27:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 19:00:21
 */
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,a,b,c,ans = 0;
  cin >> n >> a >> b >> c;
  for(int i = 1; i <= n; i++){
    ans += (i%a && i%b && i%c);
  }
  cout << ans;
  return 0;
}