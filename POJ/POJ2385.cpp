/*
 * @Date: 2019-11-12 17:22:31
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 10:50:11
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct node{
    int sum,cur;
};
const int MAXN = 1010;
const int MAXM = 40;
node dp[MAXN][MAXM]; // 前i秒移动j次的最大苹果数
int T,W;
int tree[MAXN];
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&T,&W);
    for(int i = 1; i <= T; i++){
        scanf("%d",&tree[i]);
    }
    int ans = 0;
    dp[0][0].cur = 1;
    dp[0][0].sum = 0;
    for(int i = 1; i <= T; i++){
        for(int t = 0; t <= W; t++){
            dp[i][t].sum = dp[i-1][t].sum + (dp[i-1][t].cur == tree[i]);
            dp[i][t].cur = dp[i-1][t].cur;
            if(t-1 >= 0 && dp[i-1][t-1].sum + (dp[i-1][t-1].cur != tree[i]) > dp[i][t].sum){
                dp[i][t].sum = dp[i-1][t-1].sum + (dp[i-1][t-1].cur != tree[i]);
                dp[i][t].cur = (dp[i-1][t-1].cur == 2 ? 1 : 2);

            }
            ans = max(ans,dp[i][t].sum);
        }
    }
    printf("%d",ans);
    return 0;
}