/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 15:58:31 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-08 15:58:31 
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1e3+10;
int dp[MAXN]; //选择i个药时的最大经验
int win[MAXN], lose[MAXN], use[MAXN];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> lose[i] >> win[i] >> use[i];
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= use[i]; j--){
            //选择赢和输掉
            dp[j] = max(dp[j]+lose[i], dp[j-use[i]] + win[i]);
        }
        //不够用，只能输掉
        for(int j = use[i]-1; j >= 0; j--){
            dp[j] += lose[i];
        }
    }
    printf("%lld",5ll * dp[m]);
    return 0;
}