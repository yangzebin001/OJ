/*
 * @Date: 2020-03-05 17:36:01
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-05 17:59:32
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> Edge[10010];
int n,m;
int color[10010];
int cnt;
int cnt1 = 0,cnt2 = 0;
bool dfs(int t,int c){
  color[t] = c;
  if(c == 1) cnt1++;
  else cnt2++;
  for(int i = 0; i < Edge[t].size(); i++){
    if(color[Edge[t][i]] == c) return false;
    if(color[Edge[t][i]] == 0 && !dfs(Edge[t][i],-c)){
      return false;
    }
  }
  return true;
}

int main(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int a,b;
    cin >> a >> b;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(Edge[i].size() == 0) continue;
    if(!color[i]){
      cnt1 = cnt2 = 0;
      if(!dfs(i,1)){
        cout << "Impossible" << endl;
        return 0;
      }
      cnt += min(cnt1,cnt2);
    }
  }
  
  
  cout << cnt << endl;
  return 0;
}