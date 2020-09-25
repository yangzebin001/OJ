/*
 * @Date: 2020-05-09 13:35:22
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 13:37:44
 */
#include<iostream>
using namespace std;

int main(){
  int i = 1;
  while(1){
    if(i%2 == 1 && i%3 == 1 && i %4 == 1 && i%6 == 1 && i%11 == 0){
      printf("%d",i);
      break;
    }
    i++;
  }
  return 0;
}