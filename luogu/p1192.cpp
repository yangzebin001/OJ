/*
 * @Date: 2020-02-08 20:57:10
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 21:10:00
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+10;
long long dp[MAXN];
long long dfs(int n, int k){
    if(dp[n]) return dp[n];
    long long ans = 0;
    
    return dp[n] = ans;
}
int n,k;
int MOD = 100003;
int main(){
    scanf("%d%d",&n,&k);
    dp[0] = 1;
    dp[1] = 1;
    for(int c = 2; c <= n; c++){
        
        for(int i = 1, j = c-1; i <= k && j >= 0; j--,i++){
            dp[c] = (dp[c] + dp[j]) %MOD;
        }
    }
    printf("%lld", dp[n]);
    return 0;
}