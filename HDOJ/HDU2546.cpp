/*
 * @Date: 2020-01-20 11:16:26
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-20 11:44:40
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010];
int main(){
    //首先可以用5元买价值最大的饭菜，因为5元可以换任意一个价值的饭菜，然后用m-5元取到最大的价值，（01背包问题）
    int n,m,v[1010];
    while(cin >> n && n){
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        cin >> m;
        if(m < 5){
            printf("%d\n",m);
        }else{
            sort(v,v+n);
            for(int i = 0; i < n-1; i++){
                for(int j = m-5; j >= v[i]; j--){
                    dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
                }
            }
            printf("%d\n",m-dp[m-5]-v[n-1]);
        }
    }
    return 0;
}