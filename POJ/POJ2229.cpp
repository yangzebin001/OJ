/*
 * @Date: 2019-11-05 10:43:43
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-05 11:23:41
 */
#include<iostream>
#include<cstdio>
using namespace std;
bool judge(int i){
    return (i & (i-1)) == 0;
}
const int MAXN = 1e6+10;
int dp[MAXN];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    int N;
    scanf("%d",&N);
    // 如果i为奇数，肯定有一个1，把f[i-1]的每一种情况加一个1就得到fi,所以f[i]=f[i-1]
    // 如果i为偶数，如果有1，至少有两个，则f[i-2]的每一种情况加两个1，就得到i，如果没有1，则把分解式中的每一项除2，则得到f[i/2]
    // 所以f[i]=f[i-2]+f[i/2]

    for(int i = 3; i <= N; i++){
        if(i%2==0){
            // dp[i]++;
            dp[i] = dp[i-2]+dp[i>>1];
            dp[i] %= 1000000000;
        }else{
            dp[i] = dp[i-1];
        }
        
    }
    printf("%d",dp[N]);
    return 0;
}