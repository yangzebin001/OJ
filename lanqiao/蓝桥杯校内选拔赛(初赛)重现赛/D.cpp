/*
 * @Date: 2020-03-07 13:52:09
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 13:54:50
 */
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a;
int main(){
  cin >> a;
  reverse(a.begin(),a.end());
  string b;
  for(int i = 0; i < a.size(); i++){
    if(i && i%3 == 0) b += ',';
    b += a[i];
  }
  for(int i = b.size()-1; i >= 0; i--){
    printf("%c",b[i]);
  }
  return 0;
}