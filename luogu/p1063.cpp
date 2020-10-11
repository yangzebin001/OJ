/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 14:11:42 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 14:17:19
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 200;
int dp[MAXN][MAXN];
int a[MAXN];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i+n] = a[i];
    for(int len = 2; len <= n+1; len++){
        for(int i = 1; i+len-1 <= n<<1; i++){
            int j = i+len-1;
            for(int k = i+1; k < j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i][i+n]);
    cout << ans;
    return 0;
}