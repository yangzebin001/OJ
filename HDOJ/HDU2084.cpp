/*
 * @Date: 2019-11-19 16:50:31
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 16:54:38
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 109;

int dp[MAXN][MAXN];
int N,T;
int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&T);
        for(int i = 1; i <= T; i++){
            for(int j = 1; j <= i; j++){
                scanf("%d",&dp[i][j]);
            }
        }
        for(int i = T-1; i >= 1; i--){
            for(int j = 1; j <= i; j++){
                dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}