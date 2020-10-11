#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 210;
int a[MAXN];
int dp[MAXN][MAXN],dp2[MAXN][MAXN];
int sum[MAXN];
const int INF = 0x3f3f3f3f;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i+n] = a[i];
    for(int i = 1; i <= n<<1; i++){
        sum[i] = sum[i-1]+a[i];
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i+len-1 <= n<<1; i++){
            int j = i+len-1;
            dp2[i][j] = INF;
            for(int k = i; k < j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j] + sum[j]-sum[i-1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k]+dp2[k+1][j] + sum[j]-sum[i-1]);
            }
        }
    }
    int ans = 0, ans2 = INF;
    for(int i = n,j = 1; i <= n<<1; i++,j++) ans = max(ans, dp[j][i]), ans2 = min(ans2, dp2[j][i]);
    cout <<ans2 << endl << ans << endl;
    return 0;
}