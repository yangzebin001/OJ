/*
 * @Date: 2020-04-19 14:48:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 20:57:55
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
vector<int> canplant;
map<int,pair<int,int>> topoint;
map<pair<int,int>,int> toidx;
int radius[40];
int n;
long long ans;
double dis(pair<int,int> a, pair<int,int> b){
  return sqrt((double)(a.first-b.first) * (a.first-b.first) + (double)(a.second-b.second) * (a.second-b.second));
}
void dfs(int total){
  if(total == n+1){
    long long area = 0;
    for(int i = 0; i < canplant.size(); i++){
      int a = canplant[i];
      for(int j = i + 1; j < canplant.size(); j++){
        int  b = canplant[j];
        double dista = (double)radius[a] + radius[b]; //半径之和
        double distb = dis(topoint[a],topoint[b]); //两点之间的距离
        if(distb < dista) return;
      }
      area += (long long)radius[a]*radius[a];
    }
    ans = max(ans,area);
    return;
  }
  dfs(total+1);  
  canplant.push_back(total);
  dfs(total+1);
  canplant.pop_back();
}

int main(){
  scanf("%d",&n);
  int idx = 1;
  for(int i = 0; i < n; i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    radius[idx] = c;
    pair<int,int> p = make_pair(a,b);
    topoint[idx] = p;
    toidx[p] = idx++;
  }
  dfs(1);
  printf("%lld",ans);
  return 0;
}