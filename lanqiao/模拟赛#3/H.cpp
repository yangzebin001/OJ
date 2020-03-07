/*
 * @Date: 2020-02-29 15:32:09
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-29 15:43:16
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[310][310];
int x,y;
int main(){
  int t;
  cin >> t;
  while(t--){
    memset(arr,0,sizeof(arr));
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> arr[i][j];
        if(arr[i][j] == -1){
          x = i, y = j;
        }
      }
    }
    int cnt = 0;
    for(int j = 0; j < y; j++){
      cnt += arr[x][j];
    }
    if(cnt & 1){
      cout << "JM Second" << endl;
    }else{
      cout << "JM First" << endl;
    }
  } 
  return 0;
}