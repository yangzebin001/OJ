/*
 * @Date: 2020-01-29 11:33:23
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 11:53:53
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
int arr[30030],dp[30030];
int main(){
    int n;
    while(cin >> n){
        int cnt = 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        dp[cnt++] = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > dp[cnt-1]){
                dp[cnt++] = arr[i];
            }else{
                int l = lower_bound(dp,dp+cnt,arr[i]) - dp;
                dp[l] = arr[i];
            }
        }
        cout << cnt<< endl;
    }
    return 0;
}