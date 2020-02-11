/*
 * @Date: 2020-01-27 15:13:18
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-27 15:16:18
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010],arr[1010];
int main(){
    int n;
    while(cin >> n && n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            dp[i] = arr[i];
            for(int j = 0; j < i; j++){
                if(dp[i] > dp[j])
                    dp[i] = max(dp[i],dp[j] + arr[i]);
            }
            ans = max(ans,dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}