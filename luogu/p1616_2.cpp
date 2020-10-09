/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 16:50:32 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 16:59:29
 */
#include<iostream>
using namespace std;
int n,m;
const int MAXN = 10001000;
long long dp[MAXN],v,w;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> v >> w;
        for(int j = v; j <= n; j++){
            dp[j] = max(dp[j], dp[j-v]+w);
        }
    }
    cout << dp[n] << endl;
    return 0;
}