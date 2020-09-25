#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long LL;
const LL MOD = 1e9+7;
int n, ans, maxnum;
int cnt[1000010], arr[1000010];

LL C(LL x, LL k){
    return (k == 1ll ? x : x*(x-1ll) /2) % MOD;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &arr[i]);
        cnt[arr[i]]++;
        maxnum = max(arr[i], maxnum);
    }

    for(int i = 2; i <= maxnum; i++){
        if(cnt[i] >= 2ll){
            LL times = C(cnt[i], 2LL) %MOD;
            for(int j = 1; j <= i/2; j++){
                if(j != i-j && cnt[j] >= 1 && cnt[i-j] >= 1){
                    ans += times * C(cnt[j],1) * C(cnt[i-j],1) % MOD;
                }
                if(j == i-j && cnt[j] >= 2){
                    ans += times * C(cnt[j],2) % MOD;
                }
                ans %= MOD;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}