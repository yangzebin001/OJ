/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-14 10:54:54 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-14 10:54:54 
 */
#include<bits/stdc++.h>

using namespace std;
int a[100010], vis[100010];
int n;
int ans;
int ind[100010],outd[100010];
int dfs(int x){
    if(vis[x]) return vis[x];
    vis[x] = 1;
    return vis[x] = dfs(a[x]) + 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
        outd[i]++;
        ind[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i] && outd[i] && ind[i]){
            ans = max(ans, dfs(i));
        }
    }
    cout << ans-1;
    return 0;
}