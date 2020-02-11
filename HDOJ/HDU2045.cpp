/*
 * @Date: 2020-02-09 16:08:44
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-09 18:33:24
 */
#include<iostream>
#include<algorithm>
using namespace std;
long long dp[100];
int main(){
//     n-1的色与n-2和1的色都不相同，那么n就是剩下的那个色，没有选择。
//      即就是f(n-1)
//     n-1的色与n-2不相同但与1个色一样，那么n的色就有2个色选择.
//      即就是f(n-2)*2
    dp[0] = 0;
    dp[1] = 3,dp[2] = 6,dp[3] = 6;
    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i-1]+2*dp[i-2];
    }
    int n;
    while(cin >> n){
        cout << dp[n] << endl;
    }
    return 0;
}