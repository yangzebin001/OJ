#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char str[10000010];
int cnt[100];
int main(){
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        cnt[str[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i< 26; i++){
        ans = max(ans, cnt[i]);
    }
    printf("%d", ans);
}