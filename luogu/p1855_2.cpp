/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 10:56:55 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 10:59:36
 */
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,t;
int dp[210][210];
int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        for(int x = m; x >= a; x--){
            for(int y = t; y >= b; y--){
                dp[x][y] = max(dp[x][y], dp[x-a][y-b]+1);
            }
        }
    }
    cout << dp[m][t];
    return 0;
}