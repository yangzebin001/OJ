/*
 * @Date: 2020-01-31 19:06:34
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-31 19:11:35
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int arr[1010];
int dp[1010];
const int INF = 0x3f3f3f3f;
int main(){
    int n;
    cin >> n;
    fill(dp,dp+1010,INF);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        *lower_bound(dp,dp+n,arr[i]) = arr[i];
    }
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    return 0;
}