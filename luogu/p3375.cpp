/*
 * @Date: 2020-04-25 22:28:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-25 22:34:44
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1000100],b[1000100];
int p[1000100];
int main(){
  scanf("%s%s",a+1,b+1);
  int la = strlen(a+1),lb = strlen(b+1);
  int j = 0;
  p[1] = 0;
  for(int i = 2; i <= lb; i++){
    while(j > 0 && b[i] != b[j+1]) j = p[j];
    if(b[i] == b[j+1]) j++;
    p[i] = j;
  }
  j = 0;
  for(int i = 1; i <= la; i++){
    while(j > 0 && a[i] != b[j+1]) j = p[j];
    if(a[i] == b[j+1]) j++;
    if(j == lb) printf("%d\n",i-lb+1), j = p[j];
  }
  for(int i = 1; i <= lb; i++){
    if(i == 1) printf("%d",p[i]);
    else printf(" %d",p[i]);
  }
  return 0;
}