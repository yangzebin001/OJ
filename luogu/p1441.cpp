#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 30;
int a[MAXN];
int dp[MAXN*100]; //选择前i个砝码，可以达到容量j
int vis[MAXN];
int n,m, ans;

//dp n-m个砝码做01背包，j为容量。
void d(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        for(int j = MAXN*100; j >= a[i]; j--){
            dp[j] |= dp[j-a[i]];
        }
    }
    int c = 0;
    for(int i = 1; i <= MAXN*100; i++) c += dp[i];
    ans = max(ans, c);
}
//先在n个里面丢弃m个
void dfs(int now, int cnt){
    if(cnt > m) return;
    if(now == n+1){
        if(cnt == m) d();
        return;
    }
    vis[now] = 1;
    dfs(now+1, cnt+1); //丢弃当前
    vis[now] = 0;
    dfs(now+1, cnt); //保留当前
}



int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1,0);
    cout << ans;
    return 0;
}