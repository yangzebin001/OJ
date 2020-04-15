/*
 * @Date: 2020-03-14 14:20:53
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:30:14
 */
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10010];
int n;
int l[10010],r[10010];
int main(){
  int cnt = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]) l[i] = 1;
    }
  }
  for(int i = n-2; i >= 0; i--){
    for(int j = n-1; j > i; j--){
      if(arr[j] > arr[i]) r[i] = 1;
    }
  }
  for(int i = 0; i < n; i++){
    if(l[i] && r[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}