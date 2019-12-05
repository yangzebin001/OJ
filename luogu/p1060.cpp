/*
 * @Date: 2019-11-21 20:48:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-21 20:54:36
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,dp[30010];
int main(){
    freopen("in.txt","r",stdin);
    int money,degree;
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= M; i++){
        scanf("%d%d",&money,&degree);
        for(int j = N; j >= money; j--){
            dp[j] = max(dp[j],dp[j-money]+(money*degree));
        }
    }
    printf("%d",dp[N]);
    return 0;
}