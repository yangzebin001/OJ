/*
 * @Date: 2019-10-25 22:21:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-25 22:54:43
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1e3+10;
int M[MAXN][MAXN];
int M1[MAXN][MAXN];
int vis[MAXN];
int n,m,k;
void dfs(int c){
    vis[c] = 1;
    for(int i = 1; i <= n; i++){
        if(M[c][i] && !vis[i]) dfs(i);
    }
    for(int j = 1; j <= n; j++){
        if(M[j][c] && !vis[j]) dfs(j);
    }
}
int slove(){
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(M[i][j] && !vis[i]) {
                cnt++;
                dfs(i);
            }
        }
    }
    return cnt;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        M[a][b] = 1;
        M[b][a] = 1;
        M1[a][b] = 1;
        M1[b][a] = 1;
    }
    for(int i = 1; i <= n; i++){
        M[i][i] = 1;
        M1[i][i] = 1;
    }
    for(int i = 0; i < k; i++){
        int p;
        scanf("%d",&p);
        for(int j = 0; j <= n; j++){
            M[p][j] = 0;
        }
        for(int j = 0; j <= n; j++){
            M[j][p] = 0;
        }
        int ans = slove();
        ans--;

        printf("%d\n",ans);

        for(int j = 0; j <= n; j++){
            M[p][j] = M1[p][j];
        }
        for(int j = 0; j <= n; j++){
            M[j][p] = M1[p][j];
        }
    }
    return 0;
}