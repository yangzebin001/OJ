/*
 * @Date: 2019-08-19 11:49:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-28 22:13:27
 */
#include<iostream>
#include<cstdio>
int dp[40];
int main(){
    dp[0] = 1; dp[1] = 2;
    for(int i = 2; i<= 30; i++) dp[i] = dp[i-1]+dp[i-2];
    printf("%d",dp[30]);
    return 0;
}