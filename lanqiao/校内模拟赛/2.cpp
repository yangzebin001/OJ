/*
 * @Date: 2020-03-14 14:01:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:03:07
 */
#include<iostream>

using namespace std;

int main(){
  int cnt = 0;
  for(int i = 1; i <= 1200000; i++){
    if(1200000%i == 0){
      cout << i << endl;
      cnt++;
    }
  }
  cout << cnt <<endl;
  return 0;
}