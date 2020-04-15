/*
 * @Date: 2020-03-14 14:16:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:20:07
 */
#include<iostream>
#include<algorithm>
using namespace std;

bool check(int x){
  int end = 10;
  while(x){
    if(x % 10 > end) return false;
    end = x%10;
    x /= 10;
  }
  return true;
}

int n;
int main(){
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(check(i)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}