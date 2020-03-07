/*
 * @Date: 2020-02-22 13:17:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 13:37:00
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int year,month,day;
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool checkyear(int year){
  return ((year%4 == 0 && year%100) || year%400 == 0);
}
void nextday(){
  if(month == 12 && day == 31){
    year++;
    month = 1;
    day = 1;
  }else{
    int t = months[month];
    if(checkyear(year) && month == 2) t++;
    if(day == t){
      month++;
      day = 1;
    } else{
      day++;
    }
  }
}
bool check(int year,int month,int day){
  int sum = 0;
  while(year){
    if(year%10 == 4) return false;
    sum += year%10;
    year/=10;
  }
  while(month){
    if(month%10 == 4) return false;
    sum += month%10;
    month/=10;
  }
  while(day){
    if(day%10 == 4) return false;
    sum += day%10;
    day/=10;
  }
  return sum%8==0;
}
int main(){
  // year = 2020;
  // month = 2;
  // day = 22;
  // int cnt = 0;
  // while(1){
  //   cnt += check(year,month,day);
  //   // printf("%04d%02d%02d\n",year,month,day);
  //   if(cnt == 88) break;
  //   nextday();
  // }
  // printf("%04d%02d%02d\n",year,month,day);
  printf("20220307\n");
  return 0;
}
