/*
 * @Date: 2019-11-19 17:32:33
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 17:44:02
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 60;
double dp[MAXN];
int main(){
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i< MAXN; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%.0f\n",dp[b-a+1]);
    }
    return 0;
}