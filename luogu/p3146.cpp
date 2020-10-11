/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 14:44:30 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-09 14:44:30 
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 300;

int dp[MAXN][MAXN];
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> dp[i][i];
    for(int len = 2; len <= n; len++){
        for(int i = 1; i+len-1 <= n; i++){
            int j = i+len-1;
            for(int k = i; k < j; k++){
                if(dp[i][k] == -1 || dp[k+1][j] == -1 || dp[i][k] != dp[k+1][j]) continue;
                dp[i][j] = max(dp[i][j], dp[i][k]+1);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
    return 0;
}