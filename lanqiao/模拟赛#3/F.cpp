/*
 * @Date: 2020-02-29 15:02:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-29 15:16:33
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL  x, LL y){
  if(y == 0) return x;
  return gcd(y,x%y);
}

LL fastpow(LL x, LL y,LL mod){
  LL res = 1%mod, t = x;
  while(y){
    if(y&1) res = res*t%mod;
    t = t*t%mod;
    y>>=1;
  }
  return res;
}
LL MOD= 1e9;
int main(){
  LL a,b,c,n;
  cin >>a >>b >> c >> n;
  LL bb = b/a;
  LL cc = c/a;
  LL com = gcd(cc,bb);
  LL comm = fastpow(com,n-1,MOD);
  
  
  LL ans = a*comm;
  cout <<ans;
  return 0;
}
