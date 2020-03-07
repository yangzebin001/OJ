/*
 * @Date: 2020-03-05 18:05:39
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-05 18:12:42
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
int ton(char c){
  if(isupper(c)) return c-'A';
  else return 26+(c-'a');
}
char toc(int n){
  if(n < 26) return 'A'+n;
  return 'a'+(n-26);
}
vector<int> Edge[60];
int vis[60];
int cant[60];



int main(){
  char s[5];
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%s",s);
    Edge[ton(s[0])].push_back(ton(s[1]));
    Edge[ton(s[1])].push_back(ton(s[0]));
  }

  return 0;
}