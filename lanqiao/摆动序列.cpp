/*
 * @Date: 2020-04-16 22:11:26
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-16 22:28:09
 */
#include<iostream>
#include<cstdio>
using namespace std;
int sum,n;
int da[1000], book[1000];
void dfs(int t){
  if(t > 1){
    if(t == 2) sum++; //两个数直接满足
    else if((da[t-2]-da[t-3])*(da[t-1]-da[t-3]) < 0){
      sum++;  //看最后一个是否符合条件。
    }else{
      return; //两个条件都不满足，直接退出
    }
  }
    for(int i = 1; i <= n; i++){
      if(book[i] == 0){
        da[t] = i;
        book[i] = 1;
        dfs(t+1);
        book[i] = 0;
      }
    }
}
int main(){
  sum = 0;
  scanf("%d",&n);
  dfs(0);
  printf("%d\n",sum);
  return 0;
}