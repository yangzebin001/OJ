/*
 * @Date: 2020-02-29 13:23:06
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-29 14:13:48
 */
#include<iostream>
#include<algorithm>
using namespace std;
int arr[22] = {3,5,7,11,13,19,23,29,31,37,41,53,59,61,67,71,97,101,127,197,211,431};
int vis[2000];
void dfs(int cur, int cnt, int sum){
  if(cur >= 22){
    if(cnt <= 12){
      if(sum<=1694){
        vis[sum] = 1;
      }
    }
    return;
  }
  dfs(cur+1,cnt,sum);
  dfs(cur+1,cnt+1,sum+arr[cur]);
}
int main(){
  // freopen("out.txt","w",stdout);
  // dfs(0,0,0);
  // int cnt = 0;
  // for(int i = 0; i <= 1694; i++){
  //   if(!vis[i]){
  //     cnt++;
  //     cout << i <<endl;
  //   }
  // }
  // cout << cnt <<endl;
  cout << 215 <<endl;
  return 0;
}