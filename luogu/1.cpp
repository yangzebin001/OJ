#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int cnt[26];
string s;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < s.size(); j++){
            cnt[s[j]-'a']++;
        }
        int ans = 0;
        for(int j = 0; j < 26; j++) ans = max(ans, cnt[j]);
        printf("Case #%d: %d\n",i,ans);
    }
    
    return 0;
}