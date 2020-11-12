#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int dp[N][4];

int main(){
//(1)碎

// 如果碎了就让他们碎了都-1,楼层和手机，上面的层不再考虑，只需要在下面的层测试，手机少了一部，即 dp[k-1][j-1];
// (2)不碎

// 如果没碎，下面的层不再考虑，只需要在上面的层测试，手机还是那么多，即 dp[i-k][j]
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 1000; j++){
            dp[j][i] = dp[j-1][i]+1; //当前楼层-1的最优解
            for(int k = 1; k < j && i > 1; k++){
                dp[j][i] = min(dp[j][i],max(dp[k-1][i-1],dp[j-k][i])+1); 
            }
        }
    }

    cout << dp[1000][3];
    return 0;
}