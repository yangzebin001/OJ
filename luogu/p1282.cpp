/*
 * @Date: 2020-02-13 17:17:56
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-13 18:22:27
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[1010][2],dp[1010][6010]; //前i张牌，上部分值为j时的最小翻转次数。
int n;
int main(){
    cin >> n;
    int sumup = 0,sumdown = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
        sumup += arr[i][0];
        sumdown += arr[i][1];
    }
    memset(dp,INF,sizeof(dp));
    dp[0][0] = 0; //没牌之前，最小翻转次数为0；
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 6000; j++){
            if(j-arr[i][0] >= 0)
                //不翻转   前i-1上部分为j-arr[i][0] 不翻转后，前i上部分为j-arr[i][0]+arr[i][0] = j
                dp[i][j] = dp[i-1][j-arr[i][0]];
            int t = j-arr[i][1];
            //翻转 前i-1上部分为j-arr[i][1] 翻转后，前i上部分为j-arr[i][1]+arr[i][1] = j
            if(t >= 0 && j <= 6000){
                dp[i][j] = min(dp[i][j],dp[i-1][t]+1);
            }
        }
    }
    int sum = sumup+sumdown;
    int ans = INF,tot = INF;
    for(int i = 0; i <= sum; i++){
        if(dp[n][i] != INF && abs(sum-i-i) <= tot){
            //记录差值小的
            if(tot == abs(sum-i-i)){
                ans = min(ans,dp[n][i]);
            }else{
                ans = dp[n][i];
                tot = abs(sum-i-i);
            }
        }
    }
    cout << ans <<" " ;
    return 0;
}