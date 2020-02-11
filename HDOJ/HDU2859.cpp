/*
 * @Date: 2020-02-08 18:45:29
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 19:02:12
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,dp[1010][1010];
char M[1010][1010];
int main(){
    //dp[i][j] = min(dp[i-1][j+1]+1,{以i，j为左下角，i向上扩展，j向右扩展并且M[x][j] == M[i][y] 可扩展的最大长度});
    while(scanf("%d",&n) && n){
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++) scanf("%s",M[i]);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == n-1) dp[i][j] = 1;
                else{
                    int x = i-1, y = j+1; //右上角
                    while(x >= 0 && y < n && M[x][j] == M[i][y]){
                        x--, y++;
                    }
                    int t = i-x;
                    dp[i][j] = min(t,dp[i-1][j+1]+1);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
