/*
 * @Date: 2020-02-22 14:46:52
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 15:00:58
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[5];
int main(){
  char card[5][3];
  for(int i = 0; i < 5; i++){
    scanf("%s",card[i]);
    if(card[i][0] == 'A') arr[i] = 1;
    if(card[i][0] == 'S' || card[i][0] == 'K' || card[i][0] == 'Q' || card[i][0] == 'J'){
      arr[i] = 10;
    }
    if(card[i][0] >= '0' && card[i][0] <= '9') arr[i] = card[i][0]-'0';
  }
  sort(arr,arr+5);
  int ans = 0;
  do{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 3; i++){
      cnt1 += arr[i];
    }
    if(cnt1%10) continue;
    cnt2 = arr[3]+arr[4];
    if(cnt2%10 == 0) ans = 11;
    else ans = max(ans,cnt2%10);
  }while(next_permutation(arr,arr+5));
  if(ans == 0){
    printf("so sad!\n");
  }else if(ans == 11){
    printf("so cool!\n");
  }else{
    printf("%d\n",ans);
  }
  return 0;
}