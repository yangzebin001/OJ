/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 10:23:24 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-09 10:23:24 
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int dp[50][50];
int root[50][50];

void print(int l, int r){
    if(l > r) return;
    printf("%lld ", root[l][r]);
    if(l == r) return;
    int k = root[l][r];
    print(l, k-1);
    print(k+1,r);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dp[i][i];
        dp[i][i-1] = 1;
        root[i][i] = i;
    }
    for(int len = 1; len < n; len++){
        for(int i = 1; i+len <= n; i++){
            int j = i+len;
            dp[i][j] = dp[i][i]+dp[i+1][j];////先假设i-j的根节点为i
            root[i][j] = i; //先假设i-j的根节点为i
            for(int k = i+1; k < j; k++){
                if(dp[i][j] < dp[i][k-1]*dp[k+1][j]+dp[k][k]){
                    dp[i][j] = dp[i][k-1]*dp[k+1][j]+dp[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    print(1,n);
    return 0;
}