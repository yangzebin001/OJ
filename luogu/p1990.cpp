#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 1e6+10;
int dp[MAXN], g[MAXN];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = g[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-2] + dp[i-1] + g[i-2]*2)%10000;
        g[i] = (g[i-1] + dp[i-1]) % 10000;
    }
    cout << dp[n] << endl;
    return 0;
}