/*
 * @Date: 2020-04-19 14:17:42
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 20:30:45
 */
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
char s[8] = "LANQIAO";
int vis[7];
set<string> cnt;
int cnt = 0;
void dfs(int t, string now){
  if(t == 7){
    // cout << now << endl;
    cnt.insert(now);
    return;
  }
  for(int i = 0; i < 7; i++){
    if(vis[i]) continue;
    vis[i] = 1;
    dfs(t+1,now+s[i]);
    vis[i] = 0;
  }
}
int main(){
  dfs(0,"");
  cout << cnt.size() << endl;
  return 0;
}