/*
 * @Date: 2020-02-10 15:10:05
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 15:39:44
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long dp[1010];
int main(){
//     k=3时，数列为：1,3,4,9,10,12,13..1,3,4,9,10,12,13..
// 转换成三进制就是：1,10,11,100,101,110,111..1,10,11,100,101,110,111..
// 看起来像是二进制，转化成十进制看看

// 1,2,3,4,5,6,7..1,2,3,4,5,6,7..
// 显然,第nn项就是nn.

// 程序就把这个过程逆回去，先把nn转换成二进制，再把它当成KK进制，重新转换为十进制.
    int n,k;
    long long ans = 0,cnt = 0;
    cin >> n >> k;
    while(k){
        dp[cnt++]=k%2;
        k/=2;
    }
    for(int i = 0; i < cnt; i++){
        ans += pow(n,i)*dp[i];
    }
    cout << ans;
    return 0;
}