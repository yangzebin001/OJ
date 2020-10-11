/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 15:24:10 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 15:29:37
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char s[60];
int dp[60][60];
int main(){
    int n;
    scanf("%s", s+1);
    n = strlen(s+1);
    memset(dp,0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++){
        for(int i = 1; i+len-1 <= n; i++){
            int j = i+len-1;
            if(s[i] == s[j]){
                dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
            }else{
                for(int k = i; k < j; ++ k){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}