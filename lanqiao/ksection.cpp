#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sum[100010], cnt[100010];
ll n,k,ans;
int main(){
    cin >> n >> k;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
        cnt[sum[i]%k]++;
    }
    for(int i = 0; i < k; i++){
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans;
    return 0;
}