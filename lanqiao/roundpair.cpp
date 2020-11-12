#include<bits/stdc++.h>

using namespace std;
int n,k;
const int MAXN = 1e5+10;
int cnt[MAXN], val[MAXN], dp[MAXN];
int ans;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    if(k == 0){
        for(int i = 0; i <MAXN; i++){
            if(cnt[i]) ans++;
        }
        cout << ans << endl;
        return 0;
    }

    for(int i = 0; i < k; i++){
        int m = 0;
        for(int j = i; j < MAXN; j += k){
            val[m++] = cnt[j];
        }
        dp[0] = val[0];
        for(int j = 1; j < m; j++){
            if(j == 1) dp[j] = max(dp[j-1],val[j]);
            else dp[j] = max(dp[j-1],dp[j-2]+val[j]);
        }
        ans += dp[m-1];
    }
    cout << ans;
    return 0;
}