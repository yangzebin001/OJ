/*
 * @Date: 2020-01-27 15:32:58
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-27 15:39:03
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[10010];
const int INF = 0x3f3f3f3f;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,n;
        memset(dp,INF,sizeof(dp));
        cin >>a >> b >> n;
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            int p,w;
            cin >> p >> w;
            for(int j = w; j <= b-a; j++){
                dp[j] = min(dp[j],dp[j-w]+p);
            }
        }
        if(dp[b-a] != INF){
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[b-a]);
        }else{
            printf("This is impossible.\n");
        }
    }
    return 0;
}