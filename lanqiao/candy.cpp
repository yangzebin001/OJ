/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 10:38:58 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-10 11:00:57
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int bag[110];
int n,m,k;
int dp[10000005]; //选择前i个糖果，到达状态j的最小步数(我以为2的20次方很大，结果就1e6... 让我想了好久怎么定义其他状态0.0)
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            bag[i] |= (1 << (x-1)); 
            
        }
        dp[bag[i]] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1<<m; j >= 0; j--){
            if(dp[j] == -1) continue;
            if(dp[j|bag[i]] == -1) dp[j|bag[i]] = dp[j]+1;
            dp[j|bag[i]] = min(dp[j|bag[i]], dp[j]+1);
        }
    }
    cout << dp[(1<<m)-1];
    return 0;
}