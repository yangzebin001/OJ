/*
 * @Date: 2019-11-04 22:33:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-04 22:44:12
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 400;
int dp[MAXN][MAXN];

int main(){
    int N;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i = N-1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
        }
    }
    printf("%d",dp[1][1]);
    return 0;
}