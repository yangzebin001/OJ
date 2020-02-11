/*
 * @Date: 2020-01-29 15:46:43
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 16:27:16
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int base = 400;
const int INF = 0x3f3f3f3f;
int dp[210][21][805], p[210], d[210], no[210];
int kase = 0;
//dp[i][j][k] 前i个人中选择了j个法官在|p-d| = k的情况下的最大总和
//dp[i][j][k] = 前i个人中不选择j法官，dp[i][j][k] = dp[i-1][j][k]
//              前i个人中选择j法官，dp[i][j][k] = dp[i-1][j-1][k-(p-d)]+p+d
void solve(){
    memset(dp,-INF,sizeof dp);
    dp[0][0][base] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= 800; k++){
                //不选i这个人
                dp[i][j][k] = dp[i-1][j][k];
                //选择i这个人，并且要符合条件
                if(j-1 < 0) continue; //不能越界
                int t = k - ( p[i] - d[i] );
                if(t < 0 || t > 800) continue; //不能越界
                //取一个最大的分数
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][t] + p[i] + d[i]);
            }
        }
    }
    int v = 0;
    //找到绝对值|p-d|最小的位置，即，最接近base的位置
    while(dp[n][m][base-v] < 0 && dp[n][m][base+v] < 0) v++; 
    if(dp[n][m][base-v] > dp[n][m][base+v]){
        v = base-v;
    }else{
        v = base+v;
    }

    //从后往前判断第i个人是否被选中
    int t = 0,i = n, j = m, psum = 0, dsum = 0;
    while(j > 0){
        // 如果没有选择i这个人
        if(dp[i][j][v] == dp[i-1][j][v]) i--;
        else{
            //选择了i这个人
            no[t++] = i; //保存该人的序号
            psum += p[i]; //保存辨方分数
            dsum += d[i]; //保存正方分数

            //更新状态
            v -= (p[i]-d[i]); 
            i--,j--; 
        }
    }
    printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence: \n",++kase,psum,dsum);
    //从小到大输出序号
    sort(no,no+t);
    for(int i = 0; i < t; i++){
        printf(" %d",no[i]);
    }
    printf("\n\n");
}
int main(){
    while(cin >> n >> m && n && m){
        for(int i = 1; i <= n; i++){
            cin >> p[i] >> d[i];
        }
        solve();
    }
    return 0;
}