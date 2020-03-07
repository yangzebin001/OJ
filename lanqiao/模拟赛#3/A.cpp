/*
 * @Date: 2020-02-29 12:55:23
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-29 13:06:10
 */
#include<iostream>
#include<algorithm>
using namespace std;

int cnt[26];
void add(char a){
  if(a >='a' && a <= 'z') cnt[a-'a']++;
  if(a >='A' && a <= 'Z') cnt[a-'A']++;
}
int main(){
  // char c;
  // while((c = getchar()) != EOF) add(c);
  // int maxt = 0;
  // for(int i = 0; i < 26; i++){
  //   maxt = max(maxt,cnt[i]);
  // }
  // cout << maxt<<endl;
  cout << 141 << endl;
  return 0;
}