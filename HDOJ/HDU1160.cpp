/*
 * @Date: 2020-01-29 12:29:31
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 13:27:52
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct mice{
    int w,s,idx;
}Mice[1010];
int dp[1010],pre[1010];
int cmp(mice &a, mice &b){
    return a.w < b.w;
}
void print(int c){
    if(c == -1) return;
    print(pre[c]);
    printf("%d\n",Mice[c].idx);
}
int main(){
    freopen("in.txt","r",stdin);
    int w,s;
    int kase = 0;
    memset(pre,-1,sizeof pre);
    while(cin >> w >> s){
        Mice[kase].w = w;
        Mice[kase].s = s;
        Mice[kase].idx = kase+1;
        kase++;
    }

    sort(Mice,Mice+kase,cmp);
    
    for(int i = 0; i < kase; i++){
        dp[i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(Mice[j].w < Mice[i].w && Mice[j].s > Mice[i].s){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }
    }
    int max_len = -1,max_id;
    for(int i = kase-1; i >= 0; i--){
        if(max_len < dp[i]){
            max_len = dp[i];
            max_id = i;
        }
    }
    printf("%d\n",max_len);
    print(max_id);
    return 0;
}