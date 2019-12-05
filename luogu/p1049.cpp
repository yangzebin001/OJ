/*
 * @Date: 2019-11-23 10:46:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-23 11:22:32
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 20020;
int N;
int sum,a,dp[MAXN];
int ans;
void dfs(int cost,int c){
    if(c == N){
        ans = min(ans,cost);
        return;
    }
    dfs(cost,c+1);
    if(cost-dp[c] >= 0)
        dfs(cost-dp[c],c+1);
}
int main(){
    scanf("%d%d",&sum,&N);
    ans = sum;
    for(int i = 0; i < N; i++){
        scanf("%d",&dp[i]);
    }
    dfs(sum,0);
    printf("%d",ans);
    return 0;
    
}