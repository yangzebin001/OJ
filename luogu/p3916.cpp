#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN = 1e5+10;
int n,m;
int F[MAXN];
int vis[MAXN];
vector<int> edge[MAXN];
//反向建边，能与值大的边i相通的边的A值都为i
void dfs(int root, int w){
    if(F[root]) return;
    F[root] = w;
    for(int i = 0; i < edge[root].size(); i++){
        dfs(edge[root][i], w);
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        //反向建边
        edge[b].push_back(a);
    }
    //从值大的边开始遍历
    for(int i = n; i >= 1; i--){
            dfs(i, i);
    }
    for(int i = 1; i <= n; i++){
        printf("%d ", F[i]);
    }
    return 0;
}