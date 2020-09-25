/*
 * @Date: 2020-05-09 14:04:58
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 14:23:26
 */
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
bool check(int x){
  int sum = 0;
  while(x){
    sum += x%10;
    x/=10;
  }
  return sum%2 == 0;
}
int main(){
  set<int> s;
  int n;
  scanf("%d",&n);
  int cnt = 0;
  for(int i = 2; i <= n; i+=2){
    for(int j = i+2; j <= n; j+=2){
      int k = n-i-j;
      if(k == i || k == j || k < 2) continue;
      if(check(i) && check(j) && check(k)){
      	int a = max(i,max(j,k));
      	int b = min(i,min(j,k));
      	int c = (i == a || i == b) ? (j == a || j == b) ? k : j : i;
        s.insert(c*1000+b+b*100+a);
//        cout << a << " " << b << " " << c << endl;
      }
    }
  }
  printf("%d",s.size());
  return 0;
}