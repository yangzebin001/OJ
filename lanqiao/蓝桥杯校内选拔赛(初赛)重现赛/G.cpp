/*
 * @Date: 2020-03-07 13:58:31
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 16:49:16
 */
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
string ans = "1";

void times(int a){
  string c;
  int t = 0;
  for(int i = 0; i < ans.size() || t; i++){
    if(i < ans.size()) t += a* (ans[i]-'0');
    c += '0' + (t%10);
    t /= 10;
  }
  ans = c;
}
void divs(int x, int &r){
  r = 0;
  string c;
  for(int i = ans.size()-1; i >= 0; i--){
    r = r * 10 + (ans[i]-'0');
    c += '0' + (r/x);
    r %= x;
  }
  reverse(c.begin(),c.end());
  while(c.size() > 1 && c.back() == '0') c.pop_back();
  ans = c;
}


int main(){
  int n;
  scanf("%d",&n);
  int a;
  while(n--){
    scanf("%d", &a);
    times(a);
  }
  // cout << ans << endl;
  int r = 0,cnt = 0;
  while(ans != "0"){
    divs(6,r);
    if(!r) cnt++;
    else break;
  }
  cout << cnt << endl;
  return 0;
}