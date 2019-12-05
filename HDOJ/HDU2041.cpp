/*
 * @Date: 2019-11-19 17:27:21
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 17:29:33
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 50;
int dp[MAXN];
int N;
int main(){
    scanf("%d",&N);

    dp[1] = 1;
    dp[2] = 1;
    for(int i  = 3; i < MAXN; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    for(int i = 0; i < N; i++){
        int a;
        scanf("%d",&a);
        printf("%d\n",dp[a]);
    }
    return 0;
}