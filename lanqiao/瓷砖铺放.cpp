/*
 * @Date: 2020-04-16 21:22:31
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-16 21:29:47
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
set<string> s;
void dfs(int x, string t){
  if(x < 0) return;
  if(x == 0){
    s.insert(t);
    return;
  }
  dfs(x-1,t+"1");
  dfs(x-2,t+"2");
}

int main(){
  int n;
  cin >> n;
  string a = "";
  dfs(n,a);
  cout << s.size() << endl;
  return 0;
}