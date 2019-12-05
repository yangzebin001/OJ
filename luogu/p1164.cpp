/*
 * @Date: 2019-11-22 21:22:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-22 21:57:26
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 110;
int N,M,dp[MAXN],a;
int main(){
    int ans = 0;
    scanf("%d%d",&N,&M);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%d",&a);
        for(int j = M; j >= a; j--){
            dp[j] += dp[j-a];
        }
    }
    printf("%d",dp[M]);
    return 0;
}