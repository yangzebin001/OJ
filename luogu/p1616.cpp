/*
 * @Date: 2019-11-23 11:38:09
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-23 11:44:08
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10001000;
long long T,M,dp[MAXN],V,W;
int main(){
    scanf("%lld%lld",&T,&M);
    for(int i = 1; i <= M; i++){
        scanf("%lld%lld",&W,&V);
        for(int j = W; j <= T; j++){
            dp[j] = max(dp[j],dp[j-W]+V);
        }
    }
    printf("%lld",dp[T]);
    return 0;
}