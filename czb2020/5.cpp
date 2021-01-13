#include<iostream>
using namespace std;
int mod = 1e9+7, ans = 0;
int n,k;
void dfs(int i, long long now){
    if(i == n){
        if(now % k == 0) ans++, ans %= mod;
        return;
    }
    for(int j = 1; j <= 6; j++){
        dfs(i+1, now * 10 + j);
    }
}
int main(){
    cin >> n >> k;
    dfs(0, 0);
    cout << ans;
    return 0;
}