#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN = 1010;

vector<int> edge[10010];
int K[MAXN], cnt[MAXN], vis[MAXN];
int k,n,m;

void dfs(int now){
    if(vis[now]) return;
    cnt[now]++;
    vis[now] = 1;
    for(int i = 0; i < edge[now].size(); i++){
        dfs(edge[now][i]);
    }
}

int main(){
    cin >> k >> n >> m;
    for(int i = 0; i < k; i++) cin >> K[i];
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for(int i = 0; i < k; i++){
        memset(vis, 0, sizeof(vis));
        dfs(K[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == k) ans++;
    }
    cout << ans;
    return 0;
}
