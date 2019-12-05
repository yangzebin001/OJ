/*
 * @Date: 2019-11-19 16:56:37
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 17:22:03
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 60;
int dp[MAXN];
int main(){
    int N;
    while(scanf("%d",&N) && N){
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        for(int i = 5; i <= N; i++){
            dp[i] = dp[i-1];
            dp[i] += dp[i-3];

        }
        printf("%d\n",dp[N]);
    }
    return 0;
}