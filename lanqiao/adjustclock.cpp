#include<bits/stdc++.h>

using namespace std;
queue<int> q;
int vis[100010];
int cnt = 0;
int main(){
    int n,k;
    cin >> n >> k;
    
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vis[0] = 1;
    q.push(0);
    while(cnt != n){
        int len = q.size();
        for(int i = 0; i < len; i++){
            int t = q.front();
            // cout << t << endl;
            q.pop();
            cnt++;
            if(cnt == n) break;
            if(!vis[(t+1)%n]){
                vis[(t+1)%n] = vis[t] + 1;
                q.push((t+1)%n);
            }
            if(!vis[(t+k)%n]){
                vis[(t+k)%n] = vis[t] + 1;
                q.push((t+k)%n);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, vis[i]);
    }
    cout << ans-1;
    return 0;
}