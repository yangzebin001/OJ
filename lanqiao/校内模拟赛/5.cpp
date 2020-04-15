/*
 * @Date: 2020-03-14 14:06:31
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:15:09
 */
#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
set<char> m;

int main(){
  m.insert('a');
  m.insert('e');
  m.insert('i');
  m.insert('o');
  m.insert('u');
  string s;
  cin >> s;
  int i = 0;
  int t = 0;
  
  // 1
  while(i < s.size() && !m.count(s[i])){
    t++;
    i++;
  }
  if(i >= s.size() || !t){
    printf("no\n");
    return 0;
  }
  t = 0;
  //2
  while(i < s.size() && m.count(s[i])){
    t++;
    i++;
  }
  if(i >= s.size() || !t){
    printf("no\n");
    return 0;
  }
  t = 0;
  //3
  while(i < s.size() && !m.count(s[i])){
    t++;
    i++;
  }
  if(i >= s.size() || !t){
    printf("no\n");
    return 0;
  }
  t = 0;

  while(i < s.size() && m.count(s[i])){
    t++;
    i++;
  }
  if(i < s.size() || !t) printf("no\n");
  else printf("yes\n");
  return 0;
}