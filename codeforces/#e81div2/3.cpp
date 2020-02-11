/*
 * @Date: 2020-01-29 23:41:25
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-30 00:11:09
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e5+10;
int ne[MAXN][26], cur[26];

void solve(){

    string s,a;
    cin >> s >> a;
    memset(ne,-1,sizeof(ne));
    memset(cur,-1,sizeof(cur));
    for(int i = s.size()-2; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            ne[i][j] = ne[i+1][j];
        }
        ne[i][s[i+1]-'a'] = i+1;
        
    }
    for(int i = 0; i < s.size(); i++){
        if(cur[s[i]-'a'] == -1) cur[s[i]-'a'] = i;
    }
    for(int i = 0; i < a.size(); i++){
        if(cur[a[i]-'a'] == -1){
            printf("-1\n");
            return;
        }
    }
    int ans = 1;
    int now = cur[a[0]-'a'];
    for(int i = 1; i < a.size(); i++){
        now = ne[now][a[i]-'a'];
        if(now == -1){
            now = cur[a[i]-'a'];
            ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}