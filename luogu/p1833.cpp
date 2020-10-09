/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 10:52:29 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-09 10:52:29 
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int sh,sm,eh,em;
int dp[10100];

int main(){
    scanf("%d:%d",&sh,&sm);
    scanf("%d:%d",&eh,&em);
    int m = (eh-sh)*60 + (em-sm);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t,c,p;
        cin >> t >> c >> p;
        if(p == 0){
            for(int j = t; j <= m; j++){
                dp[j] = max(dp[j], dp[j-t]+c);
            }
        }else if(p == 1){
            for(int j = m; j >= t; j--){
                dp[j] = max(dp[j], dp[j-t]+c);
            }
        }else{
            for(int j = m; j >= 0; j--){
                for(int k = 1; k <= p && k*t <= j; k++){
                    dp[j] = max(dp[j], dp[j-k*t]+k*c);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}