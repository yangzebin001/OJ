/*
 * @Date: 2019-11-23 11:28:12
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-23 11:32:17
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 20200;
int N,M,dp[MAXN],a;
int main(){
    scanf("%d%d",&M,&N);
    for(int i = 1; i <= N; i++){
        scanf("%d",&a);
        for(int j = M; j >= a; j--){
            dp[j] = max(dp[j],dp[j-a]+a);
        }
    }
    printf("%d",M-dp[M]);
    return 0;
}