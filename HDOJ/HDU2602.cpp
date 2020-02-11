/*
 * @Date: 2020-01-20 11:47:44
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-20 11:56:58
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1010],v[1010],w[1010];
int main(){
    int T;
    cin >> T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> w[i];
        for(int i = 1; i <= n; i++) cin >> v[i];
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= v[i]; j--){
                dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        cout << dp[m] << endl;
        
    }
    return 0;
}