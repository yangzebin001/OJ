/*
 * @Date: 2019-11-04 15:12:43
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-04 21:45:31
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+10;
vector<int> M[MAXN];
int maxdegree[MAXN];
int vis[MAXN];
int N;
int maxdeep=0;

void dfs(int i){
    vis[i] = 1;
    for(int j = 0; j < M[i].size(); j++){
        if(!vis[M[i][j]]) dfs(M[i][j]);
    }
}

int Kcom(){
    memset(vis,0,sizeof(vis));
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    return ans;
}
void dfs2(int i, int cnt){
    vis[i] = 1;
    maxdeep = max(maxdeep,cnt);
    for(int j = 0; j < M[i].size(); j++){
        if(!vis[M[i][j]]) dfs2(M[i][j],cnt+1);
    }
    // vis[i] = 0;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N-1; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        M[a].push_back(b);
        M[b].push_back(a);
    }
    int K = Kcom();
    if(K > 1){
        printf("Error: %d components\n",K);
    }else{
        for(int i = 1; i <= N; i++){
            memset(vis,0,sizeof(vis));
            maxdeep = 0;
            dfs2(i,1);
            maxdegree[i] = maxdeep;
        }
        for(int i = 1; i <= N; i++){
            maxdeep = max(maxdeep,maxdegree[i]);
        }
        int flag = 0;
        for(int i = 1; i <= N; i++){
            // printf("%d ",maxdegree[i]);
            if(maxdegree[i] == maxdeep) printf("%d\n",i);
        }
    }
    
    return 0;
}