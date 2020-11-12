#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+10;
int n;

vector<int> edge[MAXN];
int F[MAXN];
int ans[MAXN];
int vis[MAXN];
int s,e;
int f(int x){
    return F[x] == x ? x : F[x] = f(F[x]);
}

void dfs(int s, int idx){
    ans[idx] = s;
    vis[s] = 1;
    if(s == e){
        sort(ans,ans+idx+1);
        for(int i = 0; i < idx+1; i++){
            cout << ans[i] << " ";
        }
        return;
    } 
    for(int i = 0; i < edge[s].size(); i++){
        if(!vis[edge[s][i]]){
            dfs(edge[s][i],idx+1);
        }
    }
}

int main()
{
	scanf("%d",&n);
    for(int i = 1; i <= n; i++) F[i] = i;
	for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        
        int x = f(a), y = f(b);
        if(x == y){
            s = a, e = b;
        }else{
            F[x] = y;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }

    dfs(s,0);
	return 0;
} 