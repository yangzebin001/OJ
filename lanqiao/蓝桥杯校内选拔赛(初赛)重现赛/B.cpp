/*
 * @Date: 2020-03-07 13:09:45
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 13:18:23
 */
#include<iostream>
#include<string>
using namespace std;

int main(){
  string a;
  cin >> a;
  if((a.back()-'0')%2) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}