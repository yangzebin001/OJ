/*
 * @Date: 2020-03-07 14:32:29
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 14:44:51
 */
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
double arr[10010];
bool check(double a){
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cnt += (int)(arr[i]/a);
  }
  return cnt >= k;
}

int main(){
  scanf("%d%d",&n,&k);
  for(int i = 0; i < n; i++){
    scanf("%lf",&arr[i]);
  }
  double l = 0, r = 1e5+10;
  for(int i = 0; i < 100; i++){
    double mid = (l+r)/2;
    // cout << mid <<endl;
    if(check(mid)) l = mid;
    else r = mid;
  }
  printf("%.2f",floor(l*100)/100);
  return 0;
}