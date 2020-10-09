#include<iostream>
#include<algorithm>

using namespace std;
int n,m;
int ai[1010], dp[1010];
int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> ai[i];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            //注意：k从1开始枚举
            for(int k = 1; k <=min(ai[i],j); k++){
                dp[j] = (dp[j] + dp[j-k]) % 1000007;
            }
        }
    }
    cout << dp[m];
    return 0;
}