/*
 * @Date: 2020-01-27 17:38:56
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-27 18:16:15
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[100010][20],T[100010][20];
int main(){
    int n;
    while(scanf("%d",&n) && n){
        memset(T,0,sizeof(T));
        memset(dp,0,sizeof(dp));
        int time = 0;
        for(int i = 0; i < n; i++){
            int t,x;
            scanf("%d%d",&x,&t);
            x++;
            T[t][x]++;
            time = max(t,time);
        }
        for(int i = time; i >= 0; i--){
            for(int j = 1; j <= 11; j++){
                dp[i][j] = max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
                dp[i][j] += T[i][j];
            }
        }
        
        printf("%d\n",dp[0][6]);
    }
    return 0;
}