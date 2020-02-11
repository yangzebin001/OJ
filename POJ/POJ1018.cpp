// dp[i][j]//在第i家厂商必选的情况下，在带宽为k的情况下的最小值。
// dp[i][v[i]] = dp[i-1][j]+w[i]    v[i] <= j
// dp[i][j] =  dp[i-1][j]+w[i] v[i] > j

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int S[110],V[110][110],W[110][110];
int dp[110][1200];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,maxb = 0;
        memset(dp,INF,sizeof(dp));
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> S[i];
            for(int j = 1; j <= S[i]; j++){
                cin >> V[i][j] >> W[i][j];
                maxb = max(maxb,V[i][j]);
            }
        }
        //初始化为不选产品时，所有带宽下的金额为0
        for(int i = 0; i <= maxb; i++){
            dp[0][i] = 0;
            // dp[1][V[1][i]] = min(dp[1][V[1][i]],W[1][i]);
        }
        for(int i = 1; i <= n; i++){ //对于每一个公司
            for(int j = 1; j <= S[i]; j++){ //每个产品
                for(int k = maxb; k >= 0; k--){ //检查每个产品的在给定带宽下的最小金额。
                    if(V[i][j] <= k){ //如果带宽比k小，说明可以更小，更新V[i][j]带宽下的最小金额。
                        dp[i][V[i][j]] = min(dp[i][V[i][j]],dp[i-1][k] + W[i][j]);
                    }else{ //如果带宽比k大，说明最小带宽不变，更新到k带宽下的最小金额。
                        dp[i][k] = min(dp[i][k],dp[i-1][k] + W[i][j]);
                    }

                }
            }
        }

        double ans = 0;
        for(int i = 0; i <= maxb; i++){
            if(dp[n][i] != INF)
                ans = max(ans,1.0*i/dp[n][i]);
        }
        printf("%.3f\n",ans);
    }

    return 0;
}