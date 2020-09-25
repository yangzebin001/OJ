#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef unsigned long long ULL;
char s[10000010];
ULL h[10000010], p[10000010], base = 1331;

ULL get(int l, int r){
    return h[r] - h[l-1] * p[r-l+1];
}
int main(){
    map<ULL, int> cnt;
    scanf("%s", s+1);
    int len = strlen(s+1);
    p[0] = 1;
    for(int i = 1; i <= len; i++){
        h[i] = h[i-1]*base + (s[i]-'a' + 1);
        p[i] = p[i-1]*base;
    }
    for(int k = 1; k <= len; k++){
        for(int i = k; i <= len; i++){
            cnt[get(i-k+1, i)]++;
        }
    }
    map<ULL, int>::iterator it;
    int ans = 0;
    for(it = cnt.begin(); it != cnt.end(); it++){
        // if(it->second > ans){
        //     cout << it->first << " " << it->second << endl;
        // }
        ans = max(ans, it->second);
    }
    printf("%d", ans);
    return 0;
}