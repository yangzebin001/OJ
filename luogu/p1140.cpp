/*
 * @Date: 2020-01-22 17:24:12
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 17:56:20
 */
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int v[5][5] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int dp[210][210];
char A[200],B[200];
int tonum(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    if(c == '-') return 4;
}
int getcost(char a,char b){
    return v[tonum(a)][tonum(b)];
}
int main(){
    int lena,lenb;
    scanf("%d%s%d%s",&lena,A,&lenb,B);
    //有可能为负值
    memset(dp,-INF,sizeof(dp));
    //开局初始化
    dp[0][0] = 0;
    //行列开头算作和‘-’匹配，需要预处理。
    for(int i = 1; i <= lena; i++) dp[i][0] = dp[i-1][0] + getcost(A[i-1],'-');
    for(int j = 1; j <= lenb; j++) dp[0][j] = dp[0][j-1] + getcost(B[j-1],'-');
    //转移方程
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++){
            dp[i][j] = max(dp[i-1][j] + getcost(A[i-1],'-'),
                        max(dp[i][j-1] + getcost('-',B[j-1]),
                        dp[i-1][j-1] + getcost(A[i-1],B[j-1])));
                        
        }    
    }
    cout << dp[lena][lenb] << endl;
    return 0;
}