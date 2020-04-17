/*
 * @Date: 2020-04-16 21:31:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-16 21:51:57
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
int n,m,num1[1010],num2[1010];
set<int> unionset, allset, restset;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num1[i];
    allset.insert(num1[i]);
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> num2[i];
    if(allset.count(num2[i])) unionset.insert(num2[i]);
    else allset.insert(num2[i]);
  }
  set<int>::iterator it;
  for(it = unionset.begin(); it != unionset.end(); it++){
      printf("%d ",*it);
  }
  printf("\n");
  for(it = allset.begin(); it != allset.end(); it++){
      printf("%d ",*it);
  }
  printf("\n");
  for(int i = 0; i < n; i++){
    if(!unionset.count(num1[i])){
      restset.insert(num1[i]);
    }
  }
  for(it = restset.begin(); it != restset.end(); it++){
      printf("%d ",*it);
  }
  printf("\n");
  return 0;
}

