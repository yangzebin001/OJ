/*
 * @Date: 2020-03-07 12:59:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 16:58:50
 */
#include<iostream>
#include<algorithm>
#include<algorithm>

using namespace std;

int cnt = 0;
bool check(int x){
  for(int i = 2; i *i <= x; i++){
    if(x%i == 0) return false;
  }
  return true;
}
int main(){
  int i;
  for(i = 2; cnt < 1; i++){
    cnt += check(i);
  }
  cout << i-1 <<endl;
  cout << 1987 << endl;
  return 0;
}