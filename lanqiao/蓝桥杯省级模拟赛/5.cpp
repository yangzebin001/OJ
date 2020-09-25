/*
 * @Date: 2020-04-19 14:24:29
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 18:59:44
 */
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  string s,ans;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    ans += (char)('a'+((s[i]-'a'+3)%26));
  }
  cout << ans;
  return 0;
}