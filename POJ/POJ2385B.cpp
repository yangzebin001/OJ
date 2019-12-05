/*
 * @Date: 2019-11-19 10:51:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 10:58:57
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
const int MAXM = 40;
int a[MAXN],dp[MAXN];
int T,W;
int main(){
    scanf("%d%d",&T,&W);
    for(int i = 1; i <= T; i++){
        scanf("%d",&a[i]);
    }
    dp[0] = 0;
    for(int i = 1; i <= T; i++){
        for(int j = 0; j <= W; j++){
            dp[j] = max(dp[j],dp[j-1]);
            if((j%2 == 0 && a[i] == 1) || (j%2 == 1 && a[i] == 2)) dp[j]++;
        }
    }
    printf("%d",dp[W]);
    return 0;
}