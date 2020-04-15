/*
 * @Date: 2020-03-14 14:04:12
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:05:17
 */
#include<iostream>

using namespace std;

int main(){
  int cnt = 0;
  for(int i = 1; i <= 2019; i++){
    int t = i;
    while(t){
      if(t%10 == 9){
        cnt++;
        break;
      }
      t/=10;
    }
  }
  cout << cnt <<endl;
  return 0;
}