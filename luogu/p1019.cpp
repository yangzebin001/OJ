/*
 * @Date: 2020-01-23 17:40:53
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 18:12:39
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string words[25];
int vis[25];
int t;
int ans;
int ff = 0;
void dfs(string s){
    int n = s.size();
    for(int i = 0; i < t; i++){
        if(vis[i] >= 2) continue;
        for(int j = n-1; j > 0; j--){
            string c = s.substr(j,n-j);
            if(c.size() >= words[i].size()) break;
            if(words[i].find(c) == 0){
                vis[i]++; 
                string neww = words[i].substr(c.size());
                ans = max(ans,n+(int)neww.size());
                dfs(s+neww);
                vis[i]--;
            }
        }
    }
    
}
int main(){
    cin >> t;
    for(int i = 0; i < t; i++) cin >> words[i];
    char c;
    cin >> c;
    for(int i = 0; i < t; i++){
        if(words[i][0] == c){
            vis[i] = 1;
            ans = max(ans,(int)words[i].size());
            dfs(words[i]);
            vis[i] = 0;
        }
    }
    cout << ans;
    return 0;
}