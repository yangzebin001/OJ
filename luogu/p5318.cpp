#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 1e5+10;

vector<int> edge[MAXN];
int vis[MAXN];
int n,m,u,v;

vector<int> ans;

void dfs(int root){
    vis[root] = 1;
    ans.push_back(root);
    for(int i = 0; i < edge[root].size(); i++){
        if(!vis[edge[root][i]]){
            dfs(edge[root][i]);
        }
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    ans.push_back(1);
    while(q.size()){
        int now = q.front(); q.pop();
        for(int i = 0; i < edge[now].size(); i++){
            if(!vis[edge[now][i]]){
                vis[edge[now][i]] = 1;
                q.push(edge[now][i]);
                ans.push_back(edge[now][i]);
            }
        }
    }
    
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        sort(edge[i].begin(), edge[i].end());
    }
    dfs(1);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    memset(vis, 0, sizeof(vis));
    ans.clear();
    
    bfs();
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}