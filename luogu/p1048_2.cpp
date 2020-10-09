/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 16:50:32 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-08 16:50:32 
 */
#include<iostream>
using namespace std;
int n,m;
const int MAXN = 1010;
int dp[MAXN],v[MAXN],w[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= m; i++){
        for(int j = n; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}