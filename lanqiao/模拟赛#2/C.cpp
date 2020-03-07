/*
 * @Date: 2020-02-22 13:38:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 17:28:02
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
bool check(string a){
  int cnt9 = 0,cnt4 = 0,cnt2 = 0;
  int sum = 0;
  for(int i = 0; i < 8; i++){
    if(a[i] == '9') cnt9++;
    if(a[i] == '4') cnt4++;
    if(a[i] == '2') cnt2++;
    sum += (a[i]-'0');
  }
  return cnt9 == cnt4 && cnt2 && sum <= 52;
}
int main(){
  string A;
  int cnt = 0;
  for(char a = '0'; a <= '9'; a++){
  for(char b = '0'; b <= '9'; b++){
  for(char c = '0'; c <= '9'; c++){
  for(char d = '0'; d <= '9'; d++){
  for(char e = '0'; e <= '9'; e++){
  for(char f = '0'; f <= '9'; f++){
  for(char g = '0'; g <= '9'; g++){
  for(char h = '0'; h <= '9'; h++){
      A += a;A += b;A += c;A += d;A += e;A += f;A+=g; A+= h;
      if(check(A)){
        cnt++;
        // cout << A << endl;
      }
      A="";
  }
  }
  }
  }
  }
  }
  }
  }
  cout << cnt << endl;
  //19669500
  cout << 19669500 << endl;
  return 0;
}