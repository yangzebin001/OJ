/*
 * @Date: 2020-03-07 14:57:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 16:27:46
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
  if(b == 0) return a;
  return gcd(b,a%b);
}
LL lcm(LL a,LL b){
  LL c = gcd(max(a,b),min(a,b));
  return a*b/c;
}
int main(){
  LL a,b,c,d,n;
  cin >> n;
  cin >> a >> b >> c >> d;
  LL cnt = 0;
  cnt += n/a;
  cnt += n/b;
  cnt += n/c;
  cnt += n/d;
  cnt -= n/lcm(a,b);
  cnt -= n/lcm(a,c);
  cnt -= n/lcm(a,d);
  cnt -= n/lcm(b,c);
  cnt -= n/lcm(b,d);
  cnt -= n/lcm(c,d);
  cnt += n/lcm(lcm(a,b),c);
  cnt += n/lcm(lcm(a,b),d);
  cnt += n/lcm(lcm(a,c),d);
  cnt += n/lcm(lcm(b,c),d);
  cnt -= n/lcm(lcm(lcm(a,b),c),d);
  cout << cnt << endl;
  return 0;
}